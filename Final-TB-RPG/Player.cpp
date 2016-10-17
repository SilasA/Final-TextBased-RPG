#include "Player.h"

Player::Player(const std::string& id, int invCap, const std::string& name, int monis, int health) :
	SubSystem(id), m_inventory(invCap), m_name(name), m_monis(monis), m_health(health), m_invStartCap(invCap)
{
}

Player::Player(const std::string& id, std::vector<Weapon>& weapons, std::vector<Food> foods, const std::string& name, double monis, int health) :
	SubSystem(id), m_inventory(weapons, foods), m_name(name), m_monis(monis), m_health(health), m_invStartCap(35)
{
}

bool Player::Add(Weapon* item)
{
	if (m_inventory.Add(item)) return true;
	else
	{
		Logger::WriteLog(m_id, "Inventory Addition too large; No items Added", "log");
		std::cout << "Unable to add to inventory [full]" << std::endl;
		return false;
	}
}

bool Player::Add(Food* item)
{
	if (m_inventory.Add(item)) return true;
	else
	{
		Logger::WriteLog(m_id, "Inventory Addition too large; No items Added", "log");
		std::cout << "Unable to add to inventory [full]" << std::endl;
		return false;
	}
}

bool Player::Add(Inventory& inv)
{
	if (m_inventory.Add(inv)) return true;
	else
	{
		Logger::WriteLog(m_id, "Inventory Addition too large; No items Added", "log");
		std::cout << "Unable to add to inventory [full]" << std::endl;
		return false;
	}
}

void Player::Remove(Item* item)
{
	m_inventory.Remove(item);
}

bool Player::ChangeItemCapacity(int capacity)
{
	return m_inventory.ChangeCapacity(capacity);
}

void Player::ReleaseItems(Player* targetPlayer)
{
	targetPlayer->Add(m_inventory);
	targetPlayer->m_monis += m_monis;
	m_monis = 0;
}

int Player::Run()
{
	return 0;
}
