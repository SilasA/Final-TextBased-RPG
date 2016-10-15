#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include "GameState.h"

#include <string>

// Splash screen at the beginning of the game.
class SplashState : public GameState
{
private:
	std::string m_message;

public:
	// Tracks number of calls to SplashState::Update()
	static short counter;

	// See GameState()
	SplashState(Game* game, const std::string& id);

	// See GameState::Update()
	virtual int Update() override;
};

#endif // SPLASH_STATE_H
