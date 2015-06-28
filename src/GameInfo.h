#pragma once

#include <memory>
#include "info/PlayerInventory.h"

class GameInfo
{
public:
	GameInfo();
	~GameInfo();
	std::unique_ptr<PlayerInventory> Inventory;
};

