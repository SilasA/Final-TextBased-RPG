#include "BattleState.h"

#include <iostream>


BattleState::BattleState(Game* game, const std::string& id, Player* first, Player* second) :
	GameState(game, id), m_first(first), m_second(second)
{
}

void BattleState::draw_weapon_choice()
{
	std::vector<Item*> weaps = m_first->GetWeapons();
	for (Item* item : weaps)
		std::cout << item->Name() << std::endl;
}

int BattleState::Update()
{
	// Add variable first player
	CLEAR;

	while (true)
	{
		std::cout << "You encountered " << m_second->Name() << "." << std::endl;

		if (m_first->IsDead()) break;


		if (m_second->IsDead()) break;
	} 

	m_game->Pop();
	return 0;
}