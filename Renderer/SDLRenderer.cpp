#include "RendererCommon.h"
#include "SDLRenderer.h"
#include "PathRenderer.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"

#define DEFAULT_WINDOW_SIZE_X 640
#define DEFAULT_WINDOW_SIZE_Y 480
#define DISPLAY_FRAMERATE_IN_TITLE

void SDLRenderer::Init()
{

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI );
	mWindow = SDL_CreateWindow("Hellow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_SIZE_X, DEFAULT_WINDOW_SIZE_Y, window_flags);
	
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (mRenderer == NULL)
	{
		SDL_Log("Error creating SDL_Renderer!");
		throw std::exception();
	}

	/// Imgui ///

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	
	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(mWindow, mGlContext);
	ImGui_ImplSDLRenderer_Init(mRenderer);

	mDone = SDL_FALSE;
	mTicksCount = SDL_GetTicks();
}

void SDLRenderer::StartRender()
{
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(mRenderer);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

}

void SDLRenderer::EndRender()
{
	ImGui::Render();

	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(mRenderer);	
}


void SDLRenderer::PollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		if (event.type == SDL_QUIT)
			mDone = SDL_TRUE;
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(mWindow))
			mDone = SDL_TRUE;
	}
}

void SDLRenderer::Dispose()
{
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

bool SDLRenderer::ShouldClose()
{
	return mDone;
}

glm::vec2 SDLRenderer::GetMousePos()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return { x,y };
}
int SDLRenderer::GetMouseState()
{
	int x, y;
	return SDL_GetMouseState(&x, &y);
}
glm::ivec2 SDLRenderer::GetWindowSize()
{
	ivec2 sz;
	SDL_GetWindowSize(mWindow, &sz.x, &sz.y);
	return sz;
}
void SDLRenderer::DrawSpring(glm::vec2 p1, glm::vec2 p2,float width, int subdiv)
{
	using namespace glm;
	float delta = 1.0f/(subdiv);
	float off = delta/2;
	vec2 op = p1,np;
	vec2 dif = normalize(p2 - p1);
	vec2 norm = vec2(dif.y,-dif.x) * width;
	for (int i = 0; i < subdiv; i++, off += delta)
	{
		np = mix(p1, p2, off) + (i%2==0 ? -norm : norm);
		SDL_RenderDrawLine(mRenderer, op.x, op.y, np.x, np.y);
		op = np;
	}
	np = p2;
	SDL_RenderDrawLine(mRenderer, op.x, op.y, np.x, np.y);

}
/// 
/// must be called only once per frame
/// 
float SDLRenderer::GetDeltaTime()
{
	// Update tick counts (for next frame)
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
#ifdef DISPLAY_FRAMERATE_IN_TITLE
	mTicksCount = SDL_GetTicks();
	std::string title = std::to_string((int)(1/deltaTime));
	SDL_SetWindowTitle(mWindow, title.c_str());
#endif
	return deltaTime;
}

float SDLRenderer::GetElapsedTime()
{
	return SDL_GetTicks() / 1000.f;
}

void SDLRenderer::Draw(const PathRenderer& rend)
{
	std::vector<ivec2> data(rend.points.begin(),rend.points.end());
	if (data.size())
		SDL_RenderDrawLines(mRenderer, (SDL_Point*)&data[0], data.size());
}
