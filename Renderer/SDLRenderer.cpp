#include "SDLRenderer.h"

void SDLRenderer::Init()
{
	if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer) == -1)
	{
		printf(SDL_GetError());
		throw std::exception();
	}
	done = SDL_FALSE;
	mTicksCount =SDL_GetTicks();
}

void SDLRenderer::StartRender()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
}

void SDLRenderer::EndRender()
{
	//DrawSpring({ 100,100 }, { 500,100 }, 30, 20);

	SDL_RenderPresent(renderer);
}


void SDLRenderer::PollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			done = SDL_TRUE;
		}
	}
}

void SDLRenderer::Dispose()
{
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}
	if (window) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

bool SDLRenderer::ShouldClose()
{
	return done;
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
glm::vec2 SDLRenderer::GetScreenSize()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	return { DM.w, DM.h };
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
		SDL_RenderDrawLine(renderer, op.x, op.y, np.x, np.y);
		op = np;
	}
	np = p2;
	SDL_RenderDrawLine(renderer, op.x, op.y, np.x, np.y);

}

float SDLRenderer::GetDeltaTime()
{

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	// Update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();
	return deltaTime;
}
