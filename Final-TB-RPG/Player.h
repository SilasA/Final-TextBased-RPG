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

	Inventory m_inventory;

public:
	Player(const std::string& id, int invCap, std::string& name, double monis);

	inline std::string Name() { return m_name; }
	inline double Monis() { return m_monis; }

	bool AddItem(std::vector<Item>& container, std::vector<Item>::iterator& item);
	bool ChangeItemCapacity(int capacity);

	virtual int Update() override;
};

#endif // PLAYER_H
