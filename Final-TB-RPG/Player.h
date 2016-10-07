#ifndef PLAYER_H
#define PLAYER_H

#include "SubSystem.h"
#include "Inventory.h"

// Represents the end-user
class Player : public SubSystem
{
private:
	Inventory m_inventory;

public:
	Player(const std::string& id);

	virtual void Update() override;
};

#endif // PLAYER_H
