#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"

// Class for the game menu
class MenuState : public GameState
{
	typedef void(*Function)(Game*); // For lambdas
	typedef std::map<std::string, Function>::iterator Option; // Shorthand iterator
private:
	// Map of menu options and the corresponding functions to call
	std::map<std::string, Function> m_options;

	// Handles menu display and response.
	std::string interaction();

public:
	// See GameState()
	MenuState(Game* game, const std::string& id);

	// See GameState::Run()
	virtual int Run() override;
};

#endif // MENU_STATE_H
