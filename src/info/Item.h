#pragma once
class Item
{
public:
	Item();
	~Item();
	virtual unsigned int GetSize() = 0;
	virtual void RenderItem(float x, float y, float width, float height)=0;
};

