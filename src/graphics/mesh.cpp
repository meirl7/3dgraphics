#include "mesh.hpp"


Mesh::Mesh(std::vector<float>& buffer, size_t vertices, const int* attrs) : vertices(vertices)
{
	int vertex_size = 0;
	for (int i = 0; attrs[i]; i++)
	{
		vertex_size += attrs[i];
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_size * vertices, buffer.data(), GL_STATIC_DRAW);

	int offset = 0;

	for (int i = 0; attrs[i]; i++)
	{
		int size = attrs[i];
		glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, vertex_size * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(i);
		offset += size;
	}

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::draw(unsigned int primitive)
{
	glBindVertexArray(VAO);
	glDrawArrays(primitive, 0, vertices);
	glBindVertexArray(0);
}