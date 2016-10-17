#include "MarketState.h"

MarketState::MarketState(Game* game, const std::string& id, Player* keeper, Player* visitor) :
	GameState(game, id), m_keeper(keeper), m_visitor(visitor), 
	m_moreStorageCost(m_visitor->StartInvCap() + ((m_visitor->CurrentInvCap() - m_visitor->StartInvCap()) / 5) * 10)
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
	std::cout << "Welcome to " << m_keeper->Name() << "'s shop!" << std::endl;

	std::cout << "Your Monis: " << m_visitor->Monis() << std::endl;
	std::cout << "Your Health: " << m_visitor->Health() << std::endl;
	std::cout << "Your Storage Cap: " << m_visitor->CurrentInvCap() << std::endl;

	// Food
	std::cout << "Foods:" << std::endl;
	std::cout << "Item                     | Cost   | Health" << std::endl;

	std::vector<Food> food = m_keeper->GetFoods();
	for (Food& item : food)
	{
		std::cout << item.Name() << std::string(25 - item.Name().length(), ' ') << "| ";
		std::cout << item.Value() << std::string(7 - std::to_string(item.Value()).length(), ' ') << "| ";
		std::cout << item.Effect() << std::endl;
	}

	std::cout << "==================================================" << std::endl;

	// Weapons
	std::cout << "Weapons:" << std::endl;
	std::cout << "Item                     | Cost   | Min/Max/Crit %" << std::endl;

	std::vector<Weapon> weaps = m_keeper->GetWeapons();
	for (Weapon item : weaps)
	{
		std::cout << item.Name() << std::string(25 - item.Name().length(), ' ') << "| ";
		std::cout << item.Value() << std::string(7 - std::to_string(item.Value()).length(), ' ') << "| ";
		std::cout << item.Effect() << std::endl;
	}

	std::cout << "==================================================" << std::endl;

	// Additional storage
	std::cout << "More Storage [+5] ('storage') | cost: " << m_moreStorageCost <<  std::endl;
}

int MarketState::Run()
{
	// TODO: Add selling
	while (true)
	{
		CLEAR;
		draw_shop_stock();
		std::string line;
		Weapon* weap = nullptr;
		Food* food = nullptr;

		std::vector<Weapon>& weaps = m_keeper->GetWeapons();
		std::vector<Food>& foods = m_keeper->GetFoods();

		std::cout << "Type an item's name or 'leave': ";
		if (!std::getline(std::cin, line)) continue;
		if (line == "leave") break;
		else if (line == "storage")
		{
			if (can_afford(m_visitor, m_moreStorageCost))
			{
				m_visitor->Monis() -= m_moreStorageCost;
				m_keeper->Monis() += m_moreStorageCost;
				m_visitor->ChangeItemCapacity(m_visitor->CurrentInvCap() + 5);
				m_moreStorageCost = m_visitor->StartInvCap() + ((m_visitor->CurrentInvCap() - m_visitor->StartInvCap()) / 5) * 10;
				Logger::WriteLog(m_id, m_visitor->Name() + " bought more storage for " + std::to_string(m_moreStorageCost), "log");
			}
			else
			{
				std::cout << "You cannot afford that!" << std::endl;
				std::cin.get();
			}
		}

		for (Weapon& w : weaps)
		{
			if (w.Name() == line)
			{
				weap = &w;
				break;
			}
		}
		for (Food& f : foods) 
		{
			if (f.Name() == line)
			{
				food = &f;
				break;
			}
		}

		if (weap)
		{
			if (can_afford(m_visitor, weap->Value()))
			{
				weap->Buy(m_visitor->Monis());
				m_visitor->Add(weap);
				m_keeper->Remove(weap);
				m_keeper->Monis() += weap->Value();
				Logger::WriteLog(m_id, m_visitor->Name() + " bought " + weap->Name() + " for " + std::to_string(weap->Value()) + " monis", "log");
			}
			else
			{
				std::cout << "You cannot afford that!" << std::endl;
				std::cin.get();
			}
		}
		else if (food)
		{
			if (can_afford(m_visitor, food->Value()))
			{
				food->Buy(m_visitor->Monis());
				m_visitor->Add(food);
				m_keeper->Remove(food);
				m_keeper->Monis() += food->Value();
				Logger::WriteLog(m_id, m_visitor->Name() + " bought " + food->Name() + " for " + std::to_string(food->Value()) + " monis", "log");
			}
			else
			{
				std::cout << "You cannot afford that!" << std::endl;
				std::cin.get();
			}
		}
	}
	std::cout << m_keeper->Name() << ": Bye" << std::endl;
	return -1;
}
