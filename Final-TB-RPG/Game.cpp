#include "Game.h"
#include "SplashState.h"
#include "MenuState.h"

Game::Game(const std::string& id) : 
	SubSystem(id)
{
	Push(new SplashState(this, "Splash"));
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

int Game::Update()
{
	while (true)
	{
		if (Peek() == nullptr) break;
		Peek()->Update();
	}
	return 0;
}
