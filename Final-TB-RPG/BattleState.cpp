#include "BattleState.h"

#include <iostream>
#include <algorithm>
#include <string>


BattleState::BattleState(Game* game, const std::string& id, Player* first, Player* second) :
	GameState(game, id), m_first(first), m_second(second)
{
}

bool BattleState::draw_weapon_choice()
{
	std::vector<Item*> weaps = m_first->GetWeapons();
	if (weaps.empty()) return false;
	for (Item* item : weaps)
		std::cout << item->Name() << std::endl;
	return true;
}

bool BattleState::draw_food_choice()
{
	std::vector<Item*> foods = m_first->GetFoods();
	if (foods.empty()) return false;
	for (Item* item : foods)
		std::cout << item->Name() << std::endl;
	return true;
}

void BattleState::interaction()
{
	// ONLY FOR P1

	Item* item;
	std::string line;

	std::cout << "You encountered " << m_second->Name() << "." << std::endl;
	std::cout << "You can attack or heal: ";
	if (!std::getline(std::cin, line)) line = "ATTACK";
	std::transform(line.begin(), line.end(), line.begin(), ::toupper);
	if (line == "ATTACK")
	{
		std::cout << "What weapon do you use?" << std::endl;
		while (true)
		{
			std::cout << "Select an weapon: " << std::endl;
			if (!draw_weapon_choice())
			{
				std::cout << "Oh.. You don't have any weapons! You're screwed." << std::endl;
				return;
			}

			if (std::getline(std::cin, line))
				if ((item = m_first->FindItem(line)) != nullptr) break;
		}
		item->Use(m_second->Health());

		if (m_second->IsDead()) return;
		std::cout << m_second->Name() << " now has " << m_second->Health() << "hp." << std::endl;
	}
	else if (line == "HEAL")
	{
		std::cout << "What food do you use?" << std::endl;
		while (true)
		{
			std::cout << "Select an food: " << std::endl;
			if (!draw_food_choice())
			{
				std::cout << "Oh.. You don't have any food! You just skipped a turn." << std::endl;
				return;
			}

			if (std::getline(std::cin, line))
				if ((item = m_first->FindItem(line)) != nullptr) break;
		}
		item->Use(m_first->Health());

		std::cout << m_second->Name() << " now has " << m_second->Health() << "hp." << std::endl;
	}
}

int BattleState::Update()
{
	// TODO: Add variable first player
	CLEAR;

	while (true)
	{
		// P1's turn
		interaction();
		std::cin.get();
		
		// P2's turn
		std::vector<Item*> enemyFoods = m_second->GetFoods();
		std::vector<Item*> enemyWeaps = m_second->GetWeapons();
		// Always uses first (0th) item

		// Heals
		if (m_second->Health() <= 10 && !enemyFoods.empty())
		{
			std::cout << m_second->Name() << " used " << enemyFoods[0]->Name() << "." << std::endl;
			enemyFoods[0]->Use(m_second->Health);
		}
		// Attacks
		else
		{
			std::cout << m_second->Name() << " used " << enemyWeaps[0]->Name() << "." << std::endl;
			enemyWeaps[0]->Use(m_second->Health);
		}
		if (m_first->IsDead()) break;
	}
	// TODO: If player dies return to menu
	if (m_first->IsDead())
		std::cout << "You died." << std::endl;
	else if (m_second->IsDead())
		std::cout << m_second->Name() << " died." << std::endl;

	m_game->Pop();
	return 0;
}