#include "MenuState.h"

#include <iostream>

MenuState::MenuState(Game* game, const std::string& id) :
	GameState(game, id)
{
}

MenuState::Option MenuState::interaction()
{
	std::cout << "Select an option: " << std::endl;
	for (Option option = m_options.begin(); option != m_options.end(); option++)
	{
		std::cout << option->first << std::endl;
	}
	return Option();
}

int MenuState::Update()
{


	return 0;
}