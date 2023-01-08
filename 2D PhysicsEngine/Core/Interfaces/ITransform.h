#pragma once
#include "EngineCommon.h"
class ITransform2D {
public:
	virtual vec2 GetPos()=0;
	virtual void Update(float deltaTime)=0;
};