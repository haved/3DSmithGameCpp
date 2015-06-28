#include "IngotItem.h"
#include "../GlobalFields.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../util/UtilFields.h"

IngotItem::IngotItem()
{
}

IngotItem::~IngotItem()
{
}

glm::mat4 INGOTITEM_matrix = glm::scale(glm::mat4(), glm::vec3(1, 0.5f, 1)) * glm::perspective(0.6f, 16/9.0f, 0.1f, 4.0f) * glm::translate(glm::mat4(), glm::vec3(0.1f, 0, -2)) * 
glm::rotate(glm::mat4(), 0.4f, uFields.UnitZ) * glm::rotate(glm::mat4(), 0.6f, uFields.UnitY)*glm::rotate(glm::mat4(), -1.0f, uFields.UnitX);
void IngotItem::RenderItem(float x, float y, float width, float height)
{
	Global.OrthoRenderingEngine->DrawColoredMesh(Global.ResCollection->Ingot_m.get(), INGOTITEM_matrix, uFields.WHITE, x+4, y+4, width-8, height-8);
}
