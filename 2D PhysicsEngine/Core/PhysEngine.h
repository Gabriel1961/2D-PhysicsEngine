#pragma once
#include "../Projects/Project.h"
#include "Renderer.h"
#include <chrono>
struct SDL_Renderer;
namespace Core
{
	class PhysEngine
	{
	private:
		static Renderer* mRenderer;
		static float mDeltaTime;
		static float mElapsedFixedTime;
		static float fixedDeltaTime;
	public:
		static float GetFixedDeltaTime() { return fixedDeltaTime; }
		static void SetFixedDeltaTime(float val) { fixedDeltaTime = val; }
		static SDL_Renderer* GetSDLRenderer();
		static Renderer* GetRenderer() { return mRenderer; }
		static float GetDeltaTime() { return mDeltaTime; }
		/// <summary>
		/// gets the elapsed time from the program start
		/// </summary>
		/// <returns>seconds</returns>
		static float GetElapsedTime() { return mRenderer->GetElapsedTime(); }
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

