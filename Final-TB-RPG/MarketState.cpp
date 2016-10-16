#include "MarketState.h"

MarketState::MarketState(Game* game, const std::string& id, Player* keeper, Player* visitor) :
	GameState(game, id), m_keeper(keeper), m_visitor(visitor)
{
	Logger::WriteLog(
		m_id,
		std::string(IDEAL_SENDER_L - m_id.length(), '=')
		+ "==" + m_id + " State==================================" +
		std::string(IDEAL_SENDER_L - m_id.length(), '='),
		"log");
	Logger::WriteLog(m_id, "Shop Keeper: " + m_keeper->Name() + "  Visitor: " + m_visitor->Name());
}

void MarketState::draw_shop_stock()
{
	// Food
	std::cout << "Foods:" << std::endl;
	std::cout << "Item                     | Cost   | Health" << std::endl;

	std::vector<Food> food = m_keeper->GetFoods();
	for (Food& item : food)
	{
		std::cout << item.Name() << std::string(25 - item.Name().length(), ' ') << "|";
		std::cout << item.Value() << std::string(8 - std::to_string(item.Value()).length(), ' ') << "|";
		std::cout << item.Effect() << std::endl;
	}

	// Weapons
	std::cout << "\nWeapons:" << std::endl;
	std::cout << "Item                     | Cost   | Min/Max/Crit %" << std::endl;

	std::vector<Weapon> weaps = m_keeper->GetWeapons();
	for (Weapon item : weaps)
	{
		std::cout << item.Name() << std::string(25 - item.Name().length(), ' ') << "|";
		std::cout << item.Value() << std::string(8 - std::to_string(item.Value()).length(), ' ') << "|";
		std::cout << item.Effect() << std::endl;
	}
}

int MarketState::Run()
{
	// TODO: Add selling
	while (true)
	{
		CLEAR;
		draw_shop_stock();
		std::string line;
		Item* item;

		std::cout << "Type and items name or 'leave': ";
		if (!std::getline(std::cin, line)) continue;
		if (line == "leave") break;
		if ((item = m_keeper->FindItem(line)) != nullptr)
		{
			m_visitor->Monis() -= item->Value();
			if (item->IsFood()) m_visitor->Add((Food*)item);
			else m_visitor->Add((Weapon*)item);
			m_keeper->Remove(item);
		}
	}
	std::cout << m_keeper->Name() << ": Bye" << std::endl;
	return -1;
}
