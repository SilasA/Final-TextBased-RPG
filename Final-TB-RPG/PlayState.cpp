#include "PlayState.h"

PlayState::PlayState(const std::string& id) :
	GameState(id), m_questions(Questions("PlayState:Questions"))
{
}

void PlayState::Update()
{
}