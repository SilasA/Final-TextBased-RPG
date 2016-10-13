#include "Game.h"
#include "MenuState.h"

Game::Game(const std::string& id) : 
	SubSystem(id)
{
	Push(new MenuState(this, "Menu"));
}

void Game::Push(GameState* gameState)
{
	m_gameState.push(gameState);
}

int Game::Update()
{

	return 0;
}
