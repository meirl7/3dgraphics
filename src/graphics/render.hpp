#pragma once

#include "mesh.hpp"
#include "../game/chunk.hpp"
#include <vector>

class Render
{
public:
	Render();
	Mesh* createMesh(Chunk* chunk, Chunk* left, Chunk* right, Chunk* front, Chunk* back, Chunk* top, Chunk* bottom);
private:
	std::vector<float> buffer;
	float a, b, c, d, e, f, g, h;
	float aoFactor = 0.35f;
};