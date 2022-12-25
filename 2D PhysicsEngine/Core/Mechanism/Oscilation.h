#pragma once
#include "RendererCommon.h"
struct Oscilation {
	/// Amplitude
	float amp;
	/// Angular Velocity
	float w;
	/// Initial Angle 
	float phi0;
	/// Oscilation Direction
	vec2 dir;
	
	Oscilation(vec2 dir={0,1}, float w=1, float amp=100, float phi0=0)
		: dir(normalize(dir)), w(w), amp(amp), phi0(phi0)
	{
	}

	vec2 GetPos(float time) {
		return amp * dir * sin(w * time + phi0);
	}
};