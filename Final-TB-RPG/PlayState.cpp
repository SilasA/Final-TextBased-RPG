#include "PlayState.h"

PlayState::PlayState(Game* game, const std::string& id) :
	GameState(game, id)
{
}

int PlayState::Run()
{
	return 0;
}