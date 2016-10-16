#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"
#include "Player.h"

#include <string>

// Controls battle functionality
class BattleState : public GameState
{
private:
	// Players to duel
	// m_first is always end-user
	Player* m_first;
	Player* m_second;

	// The item name chosen in the previous turn.
	std::string m_lastItem;

	// Draws the players weapon choices from inventory
	// Returns if there are items in the list
	bool draw_weapon_choice();
	// Draws the players food choices from inventory
	// Returns if there are items in the list
	bool draw_food_choice();

	// Handles the end-users choices and turn in battle.
	void interaction();

public:
	// Takes pointers to the dueling players
	// See GameState()
	BattleState(Game* game, const std::string& id, Player* first, Player* second);

	// Loops through the battle turns until one player is dead
	// See GameState::Run()
	virtual int Run() override;

	// Returns the respective player pointer
	inline Player* First() { return m_first; }
	inline Player* Second() { return m_second; }
};

#endif // BATTLE_STATE_H
