#include "MarketState.h"

MarketState::MarketState(Game* game, const std::string& id, Player* keeper, Player* visitor) :
	GameState(game, id), m_keeper(keeper), m_visitor(visitor)
{
}

int MarketState::Run()
{
	return 0;
}
