#pragma once

#include <memory>
#include "info/PlayerInventory.h"

class GameInfo
{
public:
	void NewGame();
	std::unique_ptr<PlayerInventory> Inventory;
};