#include "PlayerEntity.h"
#include "../Scene.h"
#include "../GlobalFields.h"
#include "glm/glm.hpp"
#include "../util/Input.h"
#include <iostream>

PlayerEntity::PlayerEntity(float x, float y, std::shared_ptr<Mesh> mesh)
{
	m_mesh = mesh;
	pos.x = x;
	pos.y = y;
	UpdateModelspace();
}

PlayerEntity::~PlayerEntity()
{
	std::cout << "~PlayerEntity()" << std::endl;
}

void PlayerEntity::Update(Scene* scene)
{
	pos.x = glm::sin(Global.ElapsedTime)*10;
	pos.y = glm::cos(Global.ElapsedTime) * 7;
	rot.z = glm::atan(-InputState.RelativeMouseY, InputState.RelativeMouseX);
	UpdateModelspace();
}

void PlayerEntity::Render(Scene* scene, glm::mat4& VP)
{
	Global.BasicShaderInstance->Bind();
	Global.BasicShaderInstance->SetMVP(VP*modelspace);
	Global.BasicShaderInstance->SetModelspaceMatrix(modelspace);
	Global.BasicShaderInstance->ResetColor();
	m_mesh->Draw();
}