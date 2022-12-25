#pragma once
#include "Body.h"
#include "Oscilation.h"
class LinearOscilator
{
public:
	Body body;
	std::vector<Oscilation> oscilations;
	vec2 offset = {300,300};
	void Update(float time) {
		vec2 pos = { 0,0 };
		for (Oscilation& o : oscilations) {
			pos += o.GetPos(time);
		}
		body.position = pos + offset;
	}
};