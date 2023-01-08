#include "AutoresProj.h"
Body b1, b2;
Spring sp;
LinearOscilator osc;
PathRenderer path;
bool instantCalc=0;
void AutoresProj::Start()
{
	b1.position = { 100,100 },
	b1.gravity = 0,
	b1.isFixed = true,

	b2.mass = 10,
	b2.position = {100,200},

	sp.body1 = &b1,
	sp.body2 = &b2,
	
	osc.oscilations = { Oscilation({1,0},2*pi,100),Oscilation({0,1},2*pi,100,pi/2) };
	path.maxSize = 100;
}

void AutoresProj::Render()
{
#if 0
	b1.Render();
	b2.Render();
	sp.Render();
#endif 
	ImGui::Begin("Setari oscilator");
	bool changed = false;
	if (ImGui::Checkbox("Calculeaza drumul instant", &instantCalc)) {
		path.Clear();
	}
	
	ImGui::InputInt("Trail Length", &path.maxSize,100,1000);

	ImGui::Text("Oscilator 1");
	changed |= ImGui::SliderFloat("Phi0", &osc.oscilations[0].phi0,0,2*pi);
	changed |= ImGui::SliderFloat("Omega", &osc.oscilations[0].w,-3,3);
	changed |= ImGui::SliderFloat("A", &osc.oscilations[0].amp, 0, 200);

	ImGui::Text("Oscilator 2");
	changed |= ImGui::SliderFloat("Phi0##2", &osc.oscilations[1].phi0, 0, 2 * pi);
	changed |= ImGui::SliderFloat("Omega##2", &osc.oscilations[1].w, -3, 3);
	changed |= ImGui::SliderFloat("A##2", &osc.oscilations[1].amp, 0, 200);

	ImGui::End();
	if (instantCalc) {
		PathCalculator pc(&osc);
		int mxLen = path.maxSize;
		osc.currentTime = 0;
		path = PathRenderer(pc.GetPath(PhysEngine::GetFixedDeltaTime(), path.maxSize));
		path.maxSize = mxLen;
	}
	else {
		path.AddPoint(osc.body.position);
		if (changed) {
			path.Clear();
		}
		osc.body.Render();
	}
	PhysEngine::GetRenderer()->Draw(path);
}

void AutoresProj::Update()
{

}

void AutoresProj::FixedUpdate()
{
#if 0
	sp.Update();
	b1.Update();
	b2.Update();
	if (PhysEngine::GetRenderer()->GetMouseState())
	{
		b2.position = PhysEngine::GetRenderer()->GetMousePos();
		b2.velocity = { 0,0 };
}
	path.AddPoint(b2.position);
#endif
	osc.Update(PhysEngine::GetFixedDeltaTime());
}
