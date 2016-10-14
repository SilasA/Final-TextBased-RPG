#include "SplashState.h"
#include "MenuState.h"

#include <iostream> 
#include <stdlib.h>

SplashState::SplashState(Game* game, const std::string& id) :
	GameState(game, id)
{
	m_message = "===========================================\n>Created By:\n>Silas Agnew\n===========================================";
}

int SplashState::Update()
{
	std::cout << m_message;
	SLEEP(1500);
	std::cin.get();
	m_game->Push(new MenuState(m_game, "Menu"));
	return 0;
}
