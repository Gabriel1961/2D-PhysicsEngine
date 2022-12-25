#pragma once
#include "RendererCommon.h"
class PathRenderer {
public:
	std::deque<glm::ivec2> points;
	int maxSize = 500;
	void Clear();
	void AddPoint(const glm::vec2& point);
	PathRenderer();
	PathRenderer(const std::vector<glm::vec2>& _points);
};