#pragma once

#include "chunk.hpp"
#include "../graphics/shader.hpp"
#include "../graphics/render.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <unordered_map>

class World
{
public:
	int renderDistance = 5 * CHUNK_W;

	std::unordered_map<long long, Chunk> chunks;
	int count = 25;

	float plPosX = 0;
	float plPosZ = 0;

	World();
	void gen();
	
	Chunk* getChunk(int x, int z);
	Block* getBlock(int x, int y, int z);

	void draw(Render& render, Shader& shader);
	

};