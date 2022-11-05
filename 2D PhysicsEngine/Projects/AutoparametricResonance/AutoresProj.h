#pragma once
#include "../Project.h"
#include "../../Core/PhysCore.h"

class AutoresProj : public Project
{
	void Start() override;
	void Render() override;
	void Update() override;
	void FixedUpdate() override;
};

