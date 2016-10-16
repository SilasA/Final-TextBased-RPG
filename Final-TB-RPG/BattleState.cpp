#include "BattleState.h"
#include "Weapon.h"
#include "Food.h"

#include <iostream>
#include <algorithm>
#include <string>


BattleState::BattleState(Game* game, const std::string& id, Player* first, Player* second) :
	GameState(game, id), m_first(first), m_second(second)
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");
	Logger::WriteLog(m_id, "Player 1: " + m_first->Name() + "  Player 2: " + m_second->Name());
}

bool BattleState::draw_weapon_choice()
{
	std::vector<Weapon> weaps = m_first->GetWeapons();
	if (weaps.empty()) return false;
	for (Item& item : weaps)
		std::cout << item.Name() << std::endl;
	return true;
}

bool BattleState::draw_food_choice()
{
	bool any = false;
	std::vector<Food> foods = m_first->GetFoods();
	if (foods.empty()) return any;
	for (Item& item : foods)
	{
		if (!item.IsUsed())
		{
			std::cout << item.Name() << std::endl;
			any = true;
		}
	}
	return any;
}

void BattleState::interaction()
{
	// ONLY FOR P1
	std::string line;

	Logger::WriteLog(m_id, m_first->Name() + "'s Turn-------------------------", "log");

	std::cout << "You have " << m_first->Health() << " hp." << std::endl;
	std::cout << "You can attack or heal: ";
	if (!std::getline(std::cin, line)) line = "ATTACK";
	std::transform(line.begin(), line.end(), line.begin(), ::toupper);

	if (line == "ATTACK")
	{
		Logger::WriteLog(m_id, m_first->Name() + " is attacking~~~~~~~~~~~~", "log");
		std::cout << "What weapon do you use?" << std::endl;
		while (true)
		{
			std::cout << "Select an weapon: " << std::endl;
			if (!draw_weapon_choice())
			{
				std::cout << "Oh.. You don't have any weapons! You're screwed." << std::endl;
				return;
			}

			if (!std::getline(std::cin, line)) continue;
			if (line == "last")	line = m_lastItem;
			if (m_first->FindItem(line)) break;
			CLEAR;
		}
		Logger::WriteLog(m_id, m_first->Name() + " used " + m_first->FindItem(line)->Name(), "log");
		m_first->FindItem(line)->Use(m_second->Health());
		m_lastItem = line;

		if (m_second->IsDead())
		{
			Logger::WriteLog(m_id, m_second->Name() + " is dead", "log");
			return;
		}
		std::cout << m_second->Name() << " now has " << m_second->Health() << "hp." << std::endl;
		Logger::WriteLog(m_id, m_second->Name() + " health = " + std::to_string(m_second->Health()));
	}
	else if (line == "HEAL")
	{
		Logger::WriteLog(m_id, m_first->Name() + " is healing~~~~~~~~~~~~", "log");
		std::cout << "What food do you use?" << std::endl;
		while (true)
		{
			std::cout << "Select a food: " << std::endl;
			if (!draw_food_choice())
			{
				std::cout << "Oh.. You don't have any food! You just skipped a turn." << std::endl;
				return;
			}

			if (!std::getline(std::cin, line)) continue;
			if (line == "last")	line = m_lastItem;
			if (m_first->FindItem(line)) break;
			CLEAR;
		}
		Logger::WriteLog(m_id, m_first->Name() + " used " + m_first->FindItem(line)->Name(), "log");
		m_first->FindItem(line)->Use(m_first->Health());
		m_lastItem = line;

		if (m_first->IsDead()) return;
		std::cout << "You now have " << m_first->Health() << "hp." << std::endl;
	}
}

int BattleState::Run()
{
	CLEAR;

	std::cout << "You encountered " << m_second->Name() << " [health: " << m_second->Health() << "]." << std::endl;

	while (true)
	{
		Logger::WriteLog(m_id, "Health: 1 - " + std::to_string(m_first->Health()) + "/2 - " + std::to_string(m_second->Health()), "log");

		// P1's turn
		interaction();
		if (m_second->IsDead() || m_first->IsDead()) break;
		std::cin.get();
		
		Logger::WriteLog(m_id, m_second->Name() + "'s Turn-------------------------", "log");

		// P2's turn
		std::vector<Food> enemyFoods = m_second->GetFoods();
		std::vector<Weapon> enemyWeaps = m_second->GetWeapons();
		// Always uses first (0th) item

		// Heals
		if (m_second->Health() <= 10 && !enemyFoods.empty())
		{
			std::cout << m_second->Name() << " used " << enemyFoods[0].Name() << "." << std::endl;
			enemyFoods[0].Use(m_second->Health());
		}
		// Attacks
		else if (!enemyWeaps.empty())
		{
			std::cout << m_second->Name() << " used " << enemyWeaps[0].Name() << "." << std::endl;
			enemyWeaps[0].Use(m_first->Health());
		}
		if (m_first->IsDead() || m_second->IsDead()) break;
		std::cin.get();
		CLEAR;
	}
	if (m_first->IsDead())
	{
		std::cout << "You died." << std::endl;
		Logger::WriteLog(m_id, m_first->Name() + " died", "log");
		std::cin.get();
		return -2;
	}
	else if (m_second->IsDead())
	{
		std::cout << m_second->Name() << " died." << std::endl;
		std::cout << "You collected all of their items" << std::endl;
		m_second->ReleaseItems(m_first);
		m_game->RemoveEnemy(m_second);
		std::cin.get();
	}
	return -1;
}