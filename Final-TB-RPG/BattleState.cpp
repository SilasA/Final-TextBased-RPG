#include "BattleState.h"

BattleState::BattleState(Game* game, const std::string& id, Player* first, Player* second) :
	GameState(game, id), m_first(first), m_second(second)
{
}

int BattleState::Update()
{
	return 0;
}