#include "PlayState.h"

PlayState::PlayState(Game* game, const std::string& id) :
	GameState(game, id)
{
}

int PlayState::Update()
{
	return 0;
}