#include "StatState.h"
#include "Utilities\Logger.h"

#include <iostream>

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
	while (true)
	{
		CLEAR;
		std::cout << m_player->Name() << "'s Stats" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "Health: " << m_player->Health() << " hp" << std::endl;
		std::cout << "Monis:  " << m_player->Monis() << std::endl;
		std::cout << "Weapon--------------------Value----Min/Max/Crit %" << std::endl;

		std::vector<Weapon> weaps = m_player->GetWeapons();
		for (Weapon& item : weaps)
		{
			std::cout << item.Name() << std::string(26 - item.Name().length(), ' ');
			std::cout << item.Value() << std::string(9 - std::to_string(item.Value()).length(), ' ');
			std::cout << item.Effect() << std::endl;
		}

		std::cout << "Food----------------------Value----Health--------" << std::endl;
		std::vector<Food> food = m_player->GetFoods();
		for (Food& item : food)
		{
			std::cout << item.Name() << std::string(26 - item.Name().length(), ' ');
			std::cout << item.Value() << std::string(9 - std::to_string(item.Value()).length(), ' ');
			std::cout << item.Effect() << std::endl;
		}

		std::cout << "Type 'leave' to leave: ";
		if (!std::getline(std::cin, line)) continue;
		if (line == "leave") break;
	}
	return -1;
}
