#ifndef GAME_H
#define GAME_H

#include "SubSystem.h"
#include <stack>
#include <string>

class GameState;

class Game : public SubSystem
{
private:
	std::stack<GameState*> gameState;

public:
	Game(const std::string& id);

	GameState* Peek() { return gameState.top(); }
};

#endif // GAME_H
