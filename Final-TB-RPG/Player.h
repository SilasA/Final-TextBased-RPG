#ifndef PLAYER_H
#define PLAYER_H

#include "SubSystem.h"
#include "Inventory.h"

#include <string>

// Represents a player (npc or user)
class Player : public SubSystem
{
private:
	std::string m_name;
	int m_monis;
	int m_health;

	Inventory m_inventory;

public:
	// Constructs name, monis, and health
	// See SubSystem()
	Player(const std::string& id, int invCap, const std::string& name, int monis, int health);
	Player(const std::string& id, std::vector<Weapon>& weapons, std::vector<Food> foods, const std::string& name, double monis, int health);

	// Accessors
	inline std::string Name() { return m_name; }
	inline int& Monis() { return m_monis; }
	inline int& Health() { return m_health; }
	inline bool IsDead() { return m_health <= 0; }
	inline std::vector<Weapon>& GetWeapons() { return m_inventory.GetWeapons(); }
	inline std::vector<Food>& GetFoods() { return m_inventory.GetFoods(); }
	inline Inventory& GetInventory() { return m_inventory; }
	inline Item* FindItem(std::string& name) { return m_inventory.FindItem(name); }

	// Operator
	inline bool operator==(const Player& player) { return this->m_name == player.m_name; }

	// Add an item
	void Add(Weapon* item);
	void Add(Food* item);
	void Add(Inventory& inv);

	void Remove(Item* item);

	// Wrapper for Inventory::ChangeCapacity() to this specific player
	bool ChangeItemCapacity(int capacity);

	// Transfers all assets of the player (items and monis) to the target player
	void ReleaseItems(Player* targetPlayer);

	// Not in use
	virtual int Run() override;
};

#endif // PLAYER_H
