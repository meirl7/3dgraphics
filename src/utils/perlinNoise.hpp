#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtc/noise.hpp"

float heightNoise(float x, float z)
{
	return (glm::simplex(glm::vec2(x, z) * 0.015f) + 1.0f) * 0.5f;
}