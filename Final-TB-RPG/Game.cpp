#include "Game.h"
#include "SplashState.h"
#include "MenuState.h"

#include <iostream>
#include <cctype>

Game::Game(const std::string& id) :
	SubSystem(id), m_user("P>User", 20, get_users_name(), 50, 100)
{
	// Enemy players
	m_enemies.push_back(Player("P>Enemy>Grog", std::vector<Item>{ }, "Grog", 25, 25));

	// Shopkeepers
	m_shopkeepers.push_back(Player("P>Shop>JuanSolo", std::vector<Item>{ }, "Juan Solo", 250, 0x7fffffff));

	Push(new SplashState(this, "Splash"));
}

std::string Game::get_users_name()
{
	std::string str;
	char confirm;
	while (true)
	{
		CLEAR;
		std::cout << "Enter your name: ";
		if (!std::getline(std::cin, str)) continue;
		std::cout << "Are you sure " << str << " is your name? (y/n)" << std::endl;
		std::cin >> confirm;
		// Assumes no
		if (std::toupper(confirm) == 'Y')
			return str;
		else continue;
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

int Game::Run()
{
	while (true)
	{
		if (Peek() == nullptr) break;
		if (Peek()->Run() == -1) Pop();
	}
	return 0;
}
