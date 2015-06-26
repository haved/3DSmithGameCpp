#include "BellowEntity.h"
#include "../GlobalFields.h"
#include <iostream>

BellowEntity::BellowEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, glm::mat4& pointTrans, float xSize, float ySize) : MeshEntity(mesh, x, y, z, xSize, ySize)
{
	std::cout << "BellowEntity()" << std::endl;
	pointTranslation = pointTrans;
}

BellowEntity::~BellowEntity()
{
	std::cout << "~BellowEntity()" << std::endl;
}

void BellowEntity::Render(Scene* scene, glm::mat4& VP)
{
	Global.BasicShaderInstance->Bind();
	glm::mat4 model = modelspace * pointTranslation;
	Global.BasicShaderInstance->SetModelspaceMatrix(model);
	Global.BasicShaderInstance->SetMVP(VP*model);
	Global.BasicShaderInstance->ResetColor();
	m_mesh->Draw();
}