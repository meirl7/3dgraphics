#include "world.hpp"

inline long long pack(int x, int z)
{
	return ((long long)x << 32) | (unsigned long long)z;
}

inline int unpackX(long long k)
{
	return (int)(k >> 32);
}

inline int unpackZ(long long k)
{
	return (int)(k & 0xFFFFFFFF);
}

World::World()
{

}

void World::gen()
{
	for (int dx = 0; dx < 20; ++dx)
	{
		for (int dz = 0; dz < 20; ++dz)
		{
			long long key = pack(dx, dz);

			if (!chunks.contains(key))
			{
				Chunk ch;
				ch.xp = dx;
				ch.zp = dz;
				ch.genChunk();
				chunks[key] = ch;
			}
		}
	}
}

Chunk* World::getChunk(int x, int z)
{
	long long key = pack(x, z);
	if (chunks.contains(key))
	{
		return &chunks[key];
	}
	return nullptr;
}

Block* World::getBlock(int x, int y, int z)
{
	int dx = x / 16;
	int dz = z / 16;

	if (x < 0)
		dx--;
	if (z < 0)
		dz--;

	return &getChunk(dx, dz)->blocks.at((y * CHUNK_W + z) * CHUNK_W + x);
}


void World::draw(Render& render, Shader& shader)
{
	shader.use();
	glm::mat4 model(1.0f);

	for (auto& p : chunks)
	{
		Chunk* ch = &p.second;
		if (ch->isEdited)
		{
			int x = ch->xp, z = ch->zp;
			Chunk* left = &chunks[pack(x - 1, z)];
			Chunk* right = &chunks[pack(x + 1, z)];
			Chunk* front = &chunks[pack(x, z + 1)];
			Chunk* back = &chunks[pack(x, z - 1)];
			ch->mesh = render.createMesh(ch, left, right, front, back, nullptr, nullptr);
			ch->isEdited = false;
		}

		model = glm::translate(glm::mat4(1.0f), glm::vec3(ch->xp * CHUNK_W, 0, ch->zp * CHUNK_W));
		shader.setMat4("model", model);
		ch->mesh->draw(GL_TRIANGLES);
	}
}