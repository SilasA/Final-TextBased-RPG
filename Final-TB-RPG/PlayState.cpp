#include "PlayState.h"

PlayState::PlayState(Game* game, const std::string& id) :
	GameState(game, id), m_questions(Questions("PlayState:Questions"))
{
}

void PlayState::Update()
{
}