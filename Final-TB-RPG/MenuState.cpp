#include "MenuState.h"
#include "PlayState.h"

#include <iostream>

MenuState::MenuState(Game* game, const std::string& id) :
	GameState(game, id)
{
	// Display order is unrelated to insertion order
	m_options["exit"] = [](Game* game) { game->Pop(); };
	m_options["play"] = [](Game* game) { game->Push(new PlayState(game, "Play")); };
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
	m_options[interaction()](Peek());

	return 0;
}