#ifndef STAT_STATE_H
#define STAT_STATE_H

#include "GameState.h"
#include "Utilities\Logger.h"
#include "Player.h"

// 
class StatState : public GameState
{
private:
	Player* m_player;

public:
	StatState(Game* game, const std::string& id, Player* player);

	virtual int Run() override;
};

#endif // STAT_STATE_H
