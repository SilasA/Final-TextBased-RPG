#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"

// Game state for when the game is being played
class PlayState : public GameState
{
private:

public:
	PlayState(Game* game, const std::string& id);

	virtual int Run() override;
};

#endif // PLAY_STATE_H
