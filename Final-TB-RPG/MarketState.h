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
	Player* m_keeper;
	Player* m_visitor;

	void draw_shop_stock();

public:
	MarketState(Game* game, const std::string& id, Player* keeper, Player* visitor);

	virtual int Run() override;
};

#endif // MARKET_H
