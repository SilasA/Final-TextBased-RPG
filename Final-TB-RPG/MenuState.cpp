#include "MenuState.h"

#include <iostream>

MenuState::MenuState(const std::string& id) :
	GameState(id)
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

void MenuState::Update()
{


	
}