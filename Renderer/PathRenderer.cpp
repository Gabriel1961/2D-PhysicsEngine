#include "PathRenderer.h"
using namespace glm;
void PathRenderer::Clear()
{
	points.clear();
}

void PathRenderer::AddPoint(const glm::vec2& point)
{
	points.push_back(ivec2{ (int)point.x,(int)point.y });
	if (points.size() > maxSize)
		points.pop_front();
}

PathRenderer::PathRenderer(const std::vector<glm::vec2>& _points)
{
	points = std::deque<ivec2>(_points.size());
	for (ivec2& p : points)
		points.push_back(p);
}

PathRenderer::PathRenderer()
{
}
