#include "PlayerEntity.h"
#include "../Scene.h"
#include "../GlobalFields.h"
#include "../util/Input.h"
#include <iostream>

#define WalkSpeed 100.0f
#define Friction 8.0f
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
	glm::vec2 accel;
	if (InputState.LeftKeyDown)
		accel.x -= 1;
	if (InputState.RightKeyDown)
		accel.x += 1;
	if (InputState.UpKeyDown)
		accel.y += 1;
	if (InputState.DownKeyDown)
		accel.y -= 1;

	if (glm::length(accel) > 0)
		speed += glm::normalize(accel) * WalkSpeed * Global.DeltaTime;

	float l = glm::length(speed);
	if (l > 0.01f) {
		speed /= l;
		l -= l * Friction * Global.DeltaTime;
		speed *= l;
		pos.x += speed.x * Global.DeltaTime;
		pos.y += speed.y * Global.DeltaTime;
	}
	else if (l > 0)
		speed = glm::vec2();

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