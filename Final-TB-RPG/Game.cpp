#include "Game.h"
#include "SplashState.h"
#include "MenuState.h"
#include "Weapon.h"
#include "Food.h"

#include <iostream>
#include <algorithm>
#include <cctype>

Game::Game(const std::string& id) :
	SubSystem(id), m_user("P>User",
		std::vector<Weapon>{ Weapon("Huge Fingernail Clippers", 10, 2, 20, 5, .3f) }, 
		std::vector<Food>{ Food("Fingernail Clippings", 1, 1, 10) },
		get_users_name(), 100, 100)
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '-')
		+ "-Initializing NPCs----------------------------" +
		std::string(IDEAL_SENDER_L - m_id.length(), '-'),
		"log");

	m_user.ChangeItemCapacity(35);

	// Feel free to add players/weapons/foods

	// Enemy players
	m_enemies.push_back(Player("P>Enemy>Trump",
		std::vector<Weapon>{ Weapon("The Wall", 12, 5, 20, 10, 0) },
		std::vector<Food>{ Food("Hair", 250, 1, -10) },
		"Donald Trump", 5000, 15));
	m_enemies.push_back(Player("P>Enemy>Clinton",
		std::vector<Weapon>{ Weapon("Delete Button", 20, 1, 10, 5, .2f) },
		std::vector<Food>{ Food("Men", 10, 2, 10) },
		"Hillary Clinton", 20, 50));
	m_enemies.push_back(Player("P>Enemy>Stein",
		std::vector<Weapon>{ Weapon("Anti-Carbon", 50, 1, 50, 5, .1f) },
		std::vector<Food>{ Food("Leaves", 0, 2, 5) },
		"Jill Stein", 35, 75));
	m_enemies.push_back(Player("P>Enemy>Johnson",
		std::vector<Weapon>{ Weapon("Liberty", 60, 2, 30, 10, .05f) },
		std::vector<Food>{ Food("Exercise", 5, 1, 30) },
		"Gary Johnson", 100, 60));
	m_enemies.push_back(Player("P>Enemy>Bone", 
		std::vector<Weapon>{ Weapon("The Bone Zone", 200, 3, 30, 15, .4f) },
		std::vector<Food>{ Food("Politicians", 0, 5, 50)},
		"Ken Bone", 35, 125));
	m_enemies.push_back(Player("P>Enemy>Arnold", 
		std::vector<Weapon>{ Weapon("Ze Choppa", 50, 5, 20, 10, .1f) },
		std::vector<Food>{ Food("Pizza", 10, 2, 20)}, // What? You thought terminators ate weird food?
		"Arnold Schwarzenegger", 10, 65));

	// Shopkeepers
	m_shopkeepers.push_back(Player("P>Shop>JuanSolo",
		std::vector<Weapon>{ Weapon("Voter slip", 100, 1, 20, 10, .25f), Weapon("Sombrero", 50, 5, 25, 20, .1f) },
		std::vector<Food>{ Food("Taco", 5, 1, 10), Food("Super Taco", 100, 2, 100) },
		"Juan Solo", 250, 0x7fffffff));
	m_shopkeepers.push_back(Player("P>Shop>Brandon",
		std::vector<Weapon>{ }, 
		std::vector<Food>{ Food("Burger", 2, 1, 10), Food("Whopper", 4, 2, 20), Food("Fries", 1, 1, 5), Food("Soda", 2, 2, 8) },
		"Brandon Craft", 100, 0x7fffffff));

	Push(new SplashState(this, "Splash"));
}

std::string Game::get_users_name()
{
	char confirm;
	std::string str;
	while (true)
	{
		CLEAR;
		std::cout << "Enter your name: ";
		if (!std::getline(std::cin, str)) continue;
		return str;
	}
}

void Game::Pop() 
{
	delete Peek();
	m_gameState.pop();
}

void Game::Push(GameState* gameState)
{
	m_gameState.push(gameState);
}

void Game::RemoveEnemy(Player* player)
{
	m_enemies.erase(std::find(m_enemies.begin(), m_enemies.end(), *player));
}

int Game::Run()
{
	while (true)
	{
		if (Peek() == nullptr) break;
		int i = Peek()->Run();
		if (i == -1) Pop();
		else if (i == -2)
		{
			std::cout << "Game Over!" << std::endl;
			break;
		}
		else if (i == -3) 
		{
			std::cin.get();
			CLEAR;
			std::cout << "You defeated all the enemies." << std::endl;
			std::cout << "You won!" << std::endl;
			break;
		}
	}


	return 0;
}