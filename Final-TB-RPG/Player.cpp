#include "Player.h"

Player::Player(const std::string& id, int invCap, const std::string& name, int monis, int health) :
	SubSystem(id), m_inventory(invCap), m_name(name), m_monis(monis), m_health(health)
{
}

Player::Player(const std::string& id, std::vector<Weapon>& weapons, std::vector<Food> foods, const std::string& name, double monis, int health) :
	SubSystem(id), m_inventory(weapons, foods), m_name(name), m_monis(monis), m_health(health)
{
}

void Player::Add(Weapon* item)
{
	m_inventory.Add(item);
}

void Player::Add(Food* item)
{
	m_inventory.Add(item);
}

void Player::Add(Inventory& inv)
{
	m_inventory.Add(inv);
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
