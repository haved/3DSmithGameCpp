#include "../GlobalFields.h"
#include "HatchEntity.h"
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include "../SmithGame.h"

#include "../util/Input.h"

HatchEntity::HatchEntity(SmithGame* game, std::shared_ptr<Mesh> hatchHole, std::shared_ptr<Mesh> hatch, glm::vec3& hatchTrans, float x, float y, float xSize, float ySize)
{
	m_game = game;
	m_hatchHoleMesh = hatchHole;
	m_hatchMesh = hatch;
	m_hatchTranslation = glm::translate(m_hatchTranslation, hatchTrans);

	solid = false;
	solidXSize = xSize / 2;
	solidYSize = ySize / 2;

	pos.x = x;
	pos.y = y;
	UpdateModelspace();

	interactive = this;

	UpdateScene = false;
	RenderScene = true;
}

HatchEntity::~HatchEntity()
{
	
}

void HatchEntity::Update(Scene* scene)
{
	if (m_hatchRot < 0)
	{
		m_hatchSpeed += Global.DeltaTime * 8;
		m_hatchRot += m_hatchSpeed * Global.DeltaTime;
		if (m_hatchRot > 0)
		{
			m_hatchRot = 0;
			m_hatchSpeed = 0;
		}
	}
}

void HatchEntity::Render(Scene* scene, glm::mat4& VP)
{
	glm::mat4 MVP = VP * modelspace;
	Global.BasicShaderInstance->Bind();
	Global.BasicShaderInstance->ResetColor();
	Global.BasicShaderInstance->SetModelspaceMatrix(modelspace);
	Global.BasicShaderInstance->SetMVP(MVP);
	m_hatchHoleMesh->Draw();
	glm::mat4 hatchTransform = glm::rotate(m_hatchTranslation, m_hatchRot, glm::vec3(0, 1, 0));
	Global.BasicShaderInstance->SetModelspaceMatrix(modelspace*hatchTransform);
	Global.BasicShaderInstance->SetMVP(MVP*hatchTransform);
	m_hatchMesh->Draw();
}

void HatchEntity::OnInteractionPerformed(void* source)
{
	m_game->SetView(this);
}

void HatchEntity::OnViewChanging(std::shared_ptr<IView> prevView)
{
	m_prevView = prevView;
	m_hatchSpeed = 0;
	m_transition.SetStart(prevView.get());
}

void HatchEntity::UpdateView()
{
	m_transition.UpdateTransition(Global.DeltaTime*2);

	if (m_hatchRot > -1.5f)
		m_hatchSpeed -= Global.DeltaTime * 8;
	else
		m_hatchSpeed -= 4 * m_hatchSpeed * Global.DeltaTime;
	m_hatchRot += m_hatchSpeed * Global.DeltaTime;

	if (InputState.ExitPressed)
		m_game->SetView(m_prevView);
}

glm::vec3 HATCHENTITY_eyeOffset(0, 0, 10);
glm::vec3 HatchEntity::GetEyePos(){ return m_transition.GetEyePos(pos + HATCHENTITY_eyeOffset); }
glm::vec3 HatchEntity::GetEyeTarget(){ return m_transition.GetEyeTarget(pos); }
glm::vec3 HATCHENTITY_UP(0, 1, 0);
glm::vec3 HatchEntity::GetEyeUp(){ return m_transition.GetEyeUp(HATCHENTITY_UP); }