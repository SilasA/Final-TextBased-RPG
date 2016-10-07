#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SubSystem.h"
#include "Game.h"

#include <string>

//
class GameState : public SubSystem
{
private:

	Game* game;

public:
	GameState(const std::string& id) : 
		SubSystem(id)
	{
	}

	inline Game* Peek() { return game; }

	virtual void Input() = 0;
	virtual void Update() = 0;
};

#endif // GAME_STATE_H
