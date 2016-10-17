#ifndef MARKET_H
#define MARKET_H

#include "GameState.h"
#include "Inventory.h"
#include "Player.h"

#include <string>

// Class for interaction between a shopkeeper and the user
class MarketState : public GameState
{
private:
	// Players
	Player* m_keeper;
	Player* m_visitor;

	// Accumulative cost of more storage
	int m_moreStorageCost;

	// Outputs the shop keepers inventory
	void draw_shop_stock();

	// Checks if the player can afford the product
	inline bool can_afford(Player* player, int cost) { return player->Monis() - cost >= 0; }

public:
	// Constructs players involved
	// See GameState()
	MarketState(Game* game, const std::string& id, Player* keeper, Player* visitor);

	// See GameState::Run()
	virtual int Run() override;
};

#endif // MARKET_H
