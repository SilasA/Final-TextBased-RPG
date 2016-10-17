#ifndef GAME_H
#define GAME_H

#include "SubSystem.h"
#include "Player.h"

#include <stack>
#include <string>

#define RESERVE_IDX 9 

class GameState;

// Class for main game functionality
class Game : public SubSystem
{
private:
	// Current state of the game (m_gameState.top())
	std::stack<GameState*> m_gameState;

	// Prompts the user for their name and returns it
	std::string get_users_name();

public:
	// Players
	Player m_user;
	std::vector<Player> m_enemies;
	std::vector<Player> m_shopkeepers;

	// See SubSystem()
	Game(const std::string& id);

	// Wrapper for std::stack::pop() that deletes the object pointed to before popping
	void Pop();

	// Returns the m_gameState.top() if the stack is not empty
	inline GameState* Peek() { return m_gameState.empty() ? nullptr : m_gameState.top(); }

	// Wrapper for std::stack::push()
	void Push(GameState* gameState);

	// Removes the pointed to player from the enemy list
	void RemoveEnemy(Player* player);

	// Returns if all enemies are dead
	inline bool AreEnemiesDead() { return m_enemies.empty(); }

	// Manages stack of gamestates and calls the top's Run()
	virtual int Run() override;
};

#endif // GAME_H
