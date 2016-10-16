#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include "Player.h"

#include <map>
#include <string>

// Game state for when the game is being played
class PlayState : public GameState
{
	typedef void(*Function)(Game*, Player*, Player*); // For lambdas
	typedef std::map<std::string, Function>::iterator Option; // Shorthand iterator

private:
	// Map of actions and the corresponding functions to call
	std::map<std::string, Function> m_actions;

	// Handles menu display and response.
	std::string interaction();

public:
	PlayState(Game* game, const std::string& id);

	virtual int Run() override;
};

#endif // PLAY_STATE_H
