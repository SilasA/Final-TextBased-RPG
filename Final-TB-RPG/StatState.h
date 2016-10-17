#ifndef STAT_STATE_H
#define STAT_STATE_H

#include "GameState.h"
#include "Utilities\Logger.h"
#include "Player.h"

// Class for displaying the user's stats
class StatState : public GameState
{
private:
	// Player to display
	Player* m_player;

public:
	// Constructs player
	// See GameState()
	StatState(Game* game, const std::string& id, Player* player);

	// See GameState::Run()
	virtual int Run() override;
};

#endif // STAT_STATE_H
