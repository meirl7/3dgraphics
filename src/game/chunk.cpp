#include "chunk.hpp"
#include <cmath>

#include "../utils/perlinNoise.hpp"

Chunk::Chunk()
{
	blocks.resize(CHUNK_VOL);
}

void Chunk::genChunk()
{
	for (int z = 0; z < CHUNK_W; z++)
	{
		for (int x = 0; x < CHUNK_W; x++)
		{
			int i = 0;
			int globalX = x + (xp * CHUNK_W);
			int globalZ = z + (zp * CHUNK_W);

			int d = heightNoise(float(globalX), float(globalZ)) * 30.f;
			for (int y = 0; y < CHUNK_H; y++)
			{
				if (y <= d)
				{
					i = 1;
				}

				Block b{};
				b.id = i;

				blocks[(y * CHUNK_W + z) * CHUNK_W + x] = b;
				i = 0;
			}
		}
	}
	
}
