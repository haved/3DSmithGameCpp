#include "../GlobalFields.h"
#include "MeshEntity.h"
#include "../rendering/BasicShader.h"

#include <iostream>

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh)
{
	m_mesh = mesh;
}

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	UpdateModelspace();
}

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float xSize, float ySize)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	solidXSize = xSize / 2;
	solidYSize = ySize / 2;
	solid = true;
	UpdateModelspace();
}

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float rotX, float rotY, float rotZ)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	rot = glm::vec3(rotX, rotY, rotZ);
	UpdateModelspace();
}

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float rotX, float rotY, float rotZ, float xSize, float ySize)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	rot = glm::vec3(rotX, rotY, rotZ);
	solidXSize = xSize / 2;
	solidYSize = ySize / 2;
	solid = true;
	UpdateModelspace();
}

MeshEntity::~MeshEntity()
{
}

void MeshEntity::Update(Scene* scene){}

void MeshEntity::Render(Scene* scene, glm::mat4& VP)
{
	Global.BasicShaderInstance->Bind();
	Global.BasicShaderInstance->ResetColor();
	Global.BasicShaderInstance->SetModelspaceMatrix(modelspace);
	Global.BasicShaderInstance->SetMVP(VP*modelspace);
	m_mesh->Draw();
}