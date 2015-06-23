#pragma once

#include <glm/glm.hpp>
#include <string>
#include <GL/glew.h>

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec3 normal;
	Vertex(float x, float y, float z)
	{
		pos.x = x;
		pos.y = y;
		pos.z = z;
		color = glm::vec3(0, 1, 1);
		normal = glm::vec3(0, 0, 1);
	}
	Vertex(float x, float y, float z, float r, float g, float b)
	{
		pos.x = x;
		pos.y = y;
		pos.z = z;
		color.x = r;
		color.y = g;
		color.z = b;
		normal = glm::vec3(0, 0, 1);
	}
	Vertex(float x, float y, float z, float r, float g, float b, float nx, float ny, float nz)
	{
		pos.x = x;
		pos.y = y;
		pos.z = z;
		color.x = r;
		color.y = g;
		color.z = b;
		normal.x = nx;
		normal.y = ny;
		normal.z = nz;
	}
};

typedef struct Vertex Vertex;

class Mesh
{
public:
	Mesh(const std::string& name);
	Mesh(Vertex vertices[], uint32_t vertexCount, uint32_t indices[], uint32_t indexCount);
	~Mesh();
	void Draw();
	GLuint m_vbo;
	GLuint m_ibo;
private:
	void LoadMeshData(Vertex vertices[], uint32_t vertexCount, uint32_t indices[], uint32_t indexCount);
	int m_indicesCount;
};
