#include "MenuState.h"
#include "PlayState.h"

#include <iostream>

MenuState::MenuState(Game* game, const std::string& id) :
	GameState(game, id)
{
	// Display order is unrelated to insertion order
	m_options["Exit"] = [](Game* game) { game->Pop(); };
	m_options["Play"] = [](Game* game) { game->Push(new PlayState(game, "Play")); };
}

std::string MenuState::interaction()
{
	std::string line;
	while (true)
	{
		CLEAR;
		std::cout << "Select an option: " << std::endl;
		for (Option option = m_options.begin(); option != m_options.end(); option++)
			std::cout << option->first << std::endl;
		if (std::getline(std::cin, line) && m_options.find(line) != m_options.end()) break;
	}
	return line;
}

int MenuState::Run()
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");

	m_options[interaction()](Peek());

	return 0;
}