#include <iostream>
#include "Projects/Project.h"
#include "Core/PhysEngine.h"
#include "SDLRenderer.h"
#include "Projects/AutoparametricResonance/AutoresProj.h"
int main()
{
	AutoresProj p;
	SDLRenderer ren;
	Core::PhysEngine::LoadProject(p);
	Core::PhysEngine::RunProject(p,ren);
	return 0;
}
