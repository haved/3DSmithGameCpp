#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Mesh::Mesh(const std::string& name)
{
	std::ifstream file;
	file.open(name.c_str());

	if (!file.is_open())
	{
		std::cerr << "The file '" << name << "' could not be opened" << std::endl;
		assert(false);
	}
	
	std::cout << "The file '" << name << "' could be opened" << std::endl;

	std::string line;

	if (file.good())
		getline(file, line);

	uint32_t vertexAmount;
	uint32_t faceAmount;
	bool normals = false;
	bool colors = false;

	while (file.good())
	{
		getline(file, line);
		if (line.compare(0, 14, "element vertex")==0)
			vertexAmount = std::stoi(line.substr(15));
		else if (line.compare(0, 12, "element face") == 0)
			faceAmount = std::stoi(line.substr(13));
		else if (line.compare(0, 10, "end_header") == 0)
			break;
		normals |= line.compare(0, 17, "property float nx") == 0;
		colors |= line.compare(0, 18, "property uchar red") == 0;
	}
	assert(file.good());

	Vertex* vertices = new Vertex[vertexAmount];
	std::vector<GLuint> indices;

	for (uint32_t i = 0; (i < vertexAmount) & file.good(); i++)
	{
		getline(file, line);
		std::stringstream stream(line);
		stream >> vertices[i].pos.x;
		stream >> vertices[i].pos.y;
		stream >> vertices[i].pos.z;
		if (!stream | !normals)
			continue;
		stream >> vertices[i].normal.x;
		stream >> vertices[i].normal.y;
		stream >> vertices[i].normal.z;
		if (!stream | !colors)
			continue;
		int color = 0;
		stream >> color;
		vertices[i].color.x = color / 255.0f;
		stream >> color;
		vertices[i].color.y = color / 255.0f;
		stream >> color;
		vertices[i].color.z = color / 255.0f;
	}

	for (uint32_t i = 0; (i < faceAmount) & file.good(); i++)
	{
		std::getline(file, line);
		std::stringstream stream(line);

		GLuint i0;
		GLuint i1;
		GLuint i2;

		stream >> i0;
		stream >> i0;
		stream >> i1;
		stream >> i2;
		indices.push_back(i0);
		indices.push_back(i1);
		indices.push_back(i2);
		if (stream)
		{
			stream >> i1; //Used as i3
			indices.push_back(i0);
			indices.push_back(i2);
			indices.push_back(i1); //Used as i3
		}
	}
	
	LoadMeshData(vertices, vertexAmount, &indices[0], indices.size());
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
	glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (void*)(sizeof(glm::vec3)*2));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_indicesCount, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}
