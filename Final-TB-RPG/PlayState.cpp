#include "PlayState.h"
#include "BattleState.h"
#include "MarketState.h"
#include "StatState.h"
#include "Utilities\Logger.h"


PlayState::PlayState(Game* game, const std::string& id) :
	GameState(game, id)
{
	m_actions["Market"] =	[](Game* m_game, Player* k, Player* v) { m_game->Push(new MarketState(m_game, "Market", k, v)); };
	m_actions["Battle"] =	[](Game* m_game, Player* k, Player* v) { m_game->Push(new BattleState(m_game, "Battle", k, v)); };
	m_actions["Stats"] =	[](Game* m_game, Player* k, Player* v) { m_game->Push(new StatState(m_game, "Stats", k)); };
	m_actions["Exit"] =		[](Game* m_game, Player* k, Player* v) { m_game->Pop(); };
}

std::string PlayState::interaction()
{
	std::string line;
	while (true)
	{
		CLEAR;
		std::cout << "Select an option: " << std::endl;
		for (Option option = m_actions.begin(); option != m_actions.end(); option++)
			std::cout << option->first << std::endl;
		if (std::getline(std::cin, line) && m_actions.find(line) != m_actions.end()) break;
	}
	return line;
}

int PlayState::Run()
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");

	if (m_game->m_user.IsDead()) return -1;

	std::string line = interaction();
	int i = rand() % ((line == "Market") ? m_game->m_shopkeepers.size() : m_game->m_enemies.size());

	m_actions[line](m_game, &m_game->m_user, line == "Market" ? &m_game->m_shopkeepers[i] : &m_game->m_enemies[i]);
	return 0;
}