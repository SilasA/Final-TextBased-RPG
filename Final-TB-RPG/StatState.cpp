#include "StatState.h"
#include "Utilities\Logger.h"

#include <iostream>
#include <sstream>

StatState::StatState(Game* game, const std::string& id, Player* player) :
	GameState(game, id), m_player(player)
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");
	Logger::WriteLog(m_id, "Showing stats of " + m_player->Name());
}

int StatState::Run()
{
	std::string line;
	std::stringstream ss;
	while (true)
	{
		CLEAR;
		ss.clear();
		ss << m_player->Name() << "'s Stats" << std::endl;
		ss << "-------------------------------------------------" << std::endl;
		ss << "Health: " << m_player->Health() << " hp" << std::endl;
		ss << "Monis:  " << m_player->Monis() << std::endl;
		ss << "Taken/Available Space: " << m_player->CurrentInvUsed() << "/" << m_player->CurrentInvCap() << std::endl;
		ss << "Weapon--------------------Value----Min/Max/Crit %" << std::endl;

		std::vector<Weapon> weaps = m_player->GetWeapons();
		for (Weapon& item : weaps)
		{
			ss << item.Name() << std::string(26 - item.Name().length(), ' ');
			ss << item.Value() << std::string(9 - std::to_string(item.Value()).length(), ' ');
			ss << item.Effect() << std::endl;
		}

		ss << "Food----------------------Value----Health--------" << std::endl;
		std::vector<Food> food = m_player->GetFoods();
		for (Food& item : food)
		{
			ss << item.Name() << std::string(26 - item.Name().length(), ' ');
			ss << item.Value() << std::string(9 - std::to_string(item.Value()).length(), ' ');
			ss << item.Effect() << std::endl;
		}

		std::cout << ss.str();

		std::cout << "Type 'leave' to leave: ";
		if (!std::getline(std::cin, line)) continue;
		if (line == "leave") break;
	}
	Logger::WriteLog(m_id, "Following is quoted from in-game aka not formatted for a log.", "log");
	Logger::WriteLog(m_id, ss.str(), "log");
	return -1;
}
