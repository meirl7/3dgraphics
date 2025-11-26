#pragma once

#define CHUNK_W 16
#define CHUNK_H 128
#define CHUNK_VOL 32768

#include "../graphics/mesh.hpp"
#include <stdint.h>
#include <vector>

struct Block
{
	short id;
};

class Chunk
{
public:
	int xp, zp;

	std::vector<Block> blocks;
	Mesh* mesh;
	bool isEdited = true;
	Chunk();
	void genChunk();
};