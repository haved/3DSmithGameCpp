#include "PlayerEntity.h"
#include "../Scene.h"
#include "../GlobalFields.h"
#include "../util/Input.h"
#include <iostream>
#include <GL/glew.h>

#define WalkSpeed 100.0f
#define Friction 8.0f
PlayerEntity::PlayerEntity(float x, float y, std::shared_ptr<Mesh> mesh, std::shared_ptr<Mesh> shadow, glm::vec4& shadowColor, float xSize, float ySize)
{
	std::cout << "PlayerEntity()" << std::endl;
	m_mesh = mesh;
	m_shadow = shadow;
	m_shadowColor = shadowColor;
	pos.x = x;
	pos.y = y;
	solidXSize = xSize / 2;
	solidYSize = ySize / 2;
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
		MoveAsSolid(scene, speed.x*Global.DeltaTime, speed.y*Global.DeltaTime);
	}
	else if (l > 0)
		speed = glm::vec2();

	rot.z = glm::atan(-InputState.RelativeMouseY, InputState.RelativeMouseX);
	UpdateModelspace();
}

void PlayerEntity::Render(Scene* scene, glm::mat4& VP)
{
	Global.ColorShaderInstance->Bind();
	Global.ColorShaderInstance->SetMVP(VP*modelspace);
	Global.ColorShaderInstance->SetColor(m_shadowColor);
	glDisable(GL_DEPTH_TEST);
	m_shadow->Draw();
	glEnable(GL_DEPTH_TEST);
	Global.BasicShaderInstance->Bind();
	Global.BasicShaderInstance->SetMVP(VP*modelspace);
	Global.BasicShaderInstance->SetModelspaceMatrix(modelspace);
	Global.BasicShaderInstance->ResetColor();
	m_mesh->Draw();
}