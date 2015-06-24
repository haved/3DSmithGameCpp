#pragma once

#include "MeshEntity.h"
#include "../rendering/Mesh.h"
#include <memory>
#include <glm/glm.hpp>

class BellowEntity : public MeshEntity
{
public:
	BellowEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, glm::mat4& pointTrans, float xSize, float ySize);
	~BellowEntity();
	void Render(Scene* scene, glm::mat4& VP);
protected:
	glm::mat4 pointTranslation;
};

