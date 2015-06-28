#include "PlayerInventory.h"
#include "../GlobalFields.h"

PlayerInventory::PlayerInventory()
{
}


PlayerInventory::~PlayerInventory()
{
}

#define PINV_IconSize 64
#define PINV_overscan 20

glm::vec4 PINV_White(1, 1, 1, 1);
void PlayerInventory::Render()
{
	float width = Global.OrthoRenderingEngine->GetOrthoWidth();
	float height = Global.OrthoRenderingEngine->GetOrthoHeight();

	Global.OrthoRenderingEngine->DrawColoredTexturePart(Global.ResCollection->Box_t,
		PINV_White, width-PINV_overscan-PINV_IconSize, height-PINV_overscan-PINV_IconSize*PINV_size,
		PINV_IconSize, PINV_IconSize*4, glm::vec2(), glm::vec2(1,4));
}
