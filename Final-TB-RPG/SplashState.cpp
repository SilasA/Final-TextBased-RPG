#include "SplashState.h"
#include "MenuState.h"

#include <iostream> 
#include <stdlib.h>

short SplashState::counter = 0;

SplashState::SplashState(Game* game, const std::string& id) :
	GameState(game, id)
{
	m_message = "===========================================\n>Created By:\n>Silas Agnew\n===========================================";
}

int SplashState::Run()
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");

	counter++;

	CLEAR;
	std::cout << m_message;
	SLEEP(1500);
	std::cin.get();

	if (counter > 1) return -1;

	m_game->Push(new MenuState(m_game, "Menu"));
	return 0;
}
