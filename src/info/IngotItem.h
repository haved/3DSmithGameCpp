#pragma once

#include "Item.h"

class IngotItem : public Item
{
public:
	IngotItem();
	~IngotItem();

	unsigned int GetSize() { return 1; }
	void RenderItem(float x, float y, float width, float height);
};

