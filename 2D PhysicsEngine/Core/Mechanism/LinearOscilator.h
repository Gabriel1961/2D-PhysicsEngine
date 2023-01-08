#pragma once
#include "Body.h"
#include "Oscilation.h"
#include "Interfaces/ITransform.h"
class LinearOscilator : public ITransform2D
{
public:
	Body body;
	std::vector<Oscilation> oscilations;
	vec2 offset = {300,300};
	float currentTime=0;

	void Update(float deltaTime) override {
		vec2 pos = { 0,0 };
		currentTime += deltaTime;
		for (Oscilation& o : oscilations) {
			pos += o.GetPos(currentTime);
		}
		body.position = pos + offset;
	}

	vec2 GetPos() override { return body.GetPos(); }
};