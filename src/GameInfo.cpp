#include "GameInfo.h"

void GameInfo::NewGame()
{
	Inventory = std::make_unique<PlayerInventory>();
}
