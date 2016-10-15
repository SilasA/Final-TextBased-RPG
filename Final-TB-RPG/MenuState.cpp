#include "MenuState.h"
#include "PlayState.h"

#include <iostream>

MenuState::MenuState(Game* game, const std::string& id) :
	GameState(game, id)
{
	m_options["play"] = [](Game* game) { game->Push(new PlayState(game, "Play")); };
	m_options["exit"] = [](Game* game) { game->Pop(); };
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
		if (std::getline(std::cin, line) || m_options.find(line) != m_options.end()) break;
	}
	return line;
}

int MenuState::Update()
{
	m_options[interaction()](Peek());

	return 0;
}