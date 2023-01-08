#pragma once
#include "Mechanism/Body.h"
/// <summary>
/// Computes the path of an object given the delta time and the amount of steps to compute it for
/// </summary>
class PathCalculator {
public:
	ITransform2D* trans;
	PathCalculator(ITransform2D* transform) : trans(transform){

	}

	std::vector<vec2> GetPath(float deltaTime, int steps) {
		std::vector<vec2> points;
		for (int i = 0; i < steps; i++) {
			trans->Update(deltaTime);
			points.push_back(trans->GetPos());
		}
		return points;
	}
};