#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SubSystem.h"
#include "Game.h"

#include <string>

// Base class for all game states
// Game states control all game functionality
class GameState : public SubSystem
{
protected:

	Game* m_game;

public:
	GameState(Game* game, const std::string& id) : 
		SubSystem(id), m_game(game)
	{
	}

	inline Game* Peek() { return m_game; }

	virtual int Update() = 0;
};

#endif // GAME_STATE_H
