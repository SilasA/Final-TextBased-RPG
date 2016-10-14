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
	SplashState(Game* game, const std::string& id);

	virtual int Update() override;
};

#endif // SPLASH_STATE_H
