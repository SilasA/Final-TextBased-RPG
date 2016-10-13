#ifndef GAME_H
#define GAME_H

#include "SubSystem.h"

#include <stack>
#include <string>

class GameState;

// 
class Game : public SubSystem
{
private:
	std::stack<GameState*> m_gameState;

public:
	Game(const std::string& id);

	inline void Pop() { m_gameState.pop(); }
	inline GameState* Peek() { return m_gameState.top(); }
	void Push(GameState* gameState);

	virtual int Update() override;
};

#endif // GAME_H
