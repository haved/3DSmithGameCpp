#include "PlayerEntity.h"
#include "../Scene.h"
#include "../GlobalFields.h"

PlayerEntity::PlayerEntity(float x, float y, std::shared_ptr<Mesh> mesh)
{
	m_mesh = mesh;
	pos.x = x;
	pos.y = y;
	UpdateModelspace();
}


PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::Update(Scene* scene)
{
	pos.x += DeltaTime;
	rot.z += DeltaTime;
	UpdateModelspace();
}

void PlayerEntity::Render(Scene* scene, glm::mat4& VP)
{
	BasicShaderInstance->Bind();
	BasicShaderInstance->SetMVP(VP*modelspace);
	BasicShaderInstance->SetModelspaceMatrix(modelspace);
	BasicShaderInstance->ResetColor();
	m_mesh->Draw();
}