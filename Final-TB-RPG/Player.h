#ifndef PLAYER_H
#define PLAYER_H

#include "SubSystem.h"
#include "Inventory.h"
#include "Game.h"

#include <string>

// Represents a player (npc or user)
class Player : public SubSystem
{
private:
	std::string m_name;
	double m_monis;
	int m_health;

	Inventory m_inventory;

public:
	// Constructs name, monis, and health
	// See SubSystem()
	Player(const std::string& id, int invCap, std::string& name, double monis, int health);

	// Accessors
	inline std::string Name() { return m_name; }
	inline double Monis() { return m_monis; }
	inline int& Health() { return m_health; }
	inline bool IsDead() { return m_health <= 0; }
	inline std::vector<Item*> GetWeapons() { return m_inventory.GetWeapons(); }
	inline std::vector<Item*> GetFoods() { return m_inventory.GetFoods(); }
	inline Item* FindItem(std::string& name) { return m_inventory.FindItem(name); }

	// Wrapper for Inventory::Add() to this specific player
	bool AddItem(std::vector<Item>& container, std::vector<Item>::iterator& item);
	// Wrapper for Inventory::Remove() to this specific player
	bool RemoveItem(std::vector<Item>& container, std::vector<Item>::iterator& item);
	// Wrapper for Inventory::ChangeCapacity() to this specific player
	bool ChangeItemCapacity(int capacity);

	// Not in use
	virtual int Update() override;
};

#endif // PLAYER_H
