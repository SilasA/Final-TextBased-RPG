#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"
#include "Questions.h"

// Game state for when the game is being played
class PlayState : public GameState
{
private:
	Questions m_questions;

public:
	PlayState(Game* game, const std::string& id);

	virtual void Update() override;
};

#endif // PLAY_STATE_H
