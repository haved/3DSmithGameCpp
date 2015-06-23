#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>

Mesh::Mesh(const std::string& name)
{
	assert(false);
}

void MESH_CalcNormals(Vertex v[], uint32_t i[], uint32_t indexCount)
{
	for (uint32_t j = 0; j < indexCount; j += 3)
	{
		uint32_t j0 = i[j];
		uint32_t j1 = i[j + 1];
		uint32_t j2 = i[j + 2];

		glm::vec3 v1 = v[j1].pos - v[j0].pos;
		glm::vec3 v2 = v[j2].pos - v[j0].pos;

		glm::vec3 normal = glm::normalize(glm::cross(v1, v2));

		v[j0].normal += normal;
		v[j1].normal += normal;
		v[j1].normal += normal;
	}
}

Mesh::Mesh(Vertex vertices[], uint32_t vertexCount, uint32_t indices[], uint32_t indexCount)
{
	MESH_CalcNormals(vertices, indices, indexCount);
	LoadMeshData(vertices, vertexCount, indices, indexCount);
}

Mesh::~Mesh()
{
	std::cout << "Deleted mesh with vbo: " << m_vbo << std::endl;
	if (m_indicesCount != 0)
	{
		glDeleteBuffers(1, &m_vbo);
		glDeleteBuffers(1, &m_ibo);
	}
}

void Mesh::LoadMeshData(Vertex vertices[], uint32_t vertexCount, uint32_t indices[], uint32_t indexCount)
{
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	std::cout << "Allocated mesh with vbo: " << m_vbo << std::endl;

	m_indicesCount = indexCount;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertexCount, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t)*indexCount, indices, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)sizeof(glm::vec3));
	glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (void*)sizeof(glm::vec3));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_indicesCount, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}
