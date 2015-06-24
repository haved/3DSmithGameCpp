#include "MeshEntity.h"
#include "../rendering/BasicShader.h"

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	UpdateModelspace();
}

MeshEntity::MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float rotX, float rotY, float rotZ)
{
	m_mesh = mesh;
	pos = glm::vec3(x, y, z);
	rot = glm::vec3(rotX, rotY, rotZ);
	UpdateModelspace();
}

MeshEntity::~MeshEntity()
{
}

void MeshEntity::Update(Scene* scene){}

extern BasicShader* BasicShaderInstance;

void MeshEntity::Render(Scene* scene, glm::mat4& VP)
{
	BasicShaderInstance->Bind();
	BasicShaderInstance->ResetColor();
	BasicShaderInstance->SetModelspaceMatrix(modelspace);
	BasicShaderInstance->SetMVP(VP*modelspace);
	m_mesh->Draw();
}