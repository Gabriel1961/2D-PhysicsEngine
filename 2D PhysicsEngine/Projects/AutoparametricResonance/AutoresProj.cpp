#include "AutoresProj.h"
#include <iostream>
#include <string>
Body b1, b2;
Spring sp;
void AutoresProj::Start()
{
	b1 = {
		.position = { 100,100 },
		.gravity = 0,
		.isFixed = true,
	};
	b2 = {
		.mass = 10,
		.position = {100,200},
	};
	sp = {
		.body1 = &b1,
		.body2 = &b2,
	};
}

void AutoresProj::Render()
{
	b1.Render();
	b2.Render();
	sp.Render();
}

void AutoresProj::Update()
{
	sp.Update();
	b1.Update();
	b2.Update();
	if (PhysEngine::GetRenderer()->GetMouseState())
	{
		b2.position = PhysEngine::GetRenderer()->GetMousePos();
		b2.velocity = { 0,0 };
	}
	//printf("%f\n", PhysEngine::GetDeltaTime());
}

void AutoresProj::FixedUpdate()
{
}
