#pragma once
#include "../Projects/Project.h"
#include "Renderer.h"
struct SDL_Renderer;
namespace Core
{
	class PhysEngine
	{
	private:
		static Renderer* mRenderer;
		static float mDeltaTime;
	public:
		static SDL_Renderer* GetSDLRenderer();
		static Renderer* GetRenderer() { return mRenderer; }
		static float GetDeltaTime() { return mDeltaTime; }
		/// <summary>
		/// calls Project::Load
		/// </summary>
		/// <param name="project"></param>
		static void LoadProject(Project & project);
		
		/// <summary>
		/// Blocks current thread and runs the project
		/// </summary>
		/// <param name="project"></param>
		static void RunProject(Project& project, Renderer& renderer);


	};
}

