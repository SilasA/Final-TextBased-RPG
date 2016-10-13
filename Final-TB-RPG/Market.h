#ifndef MARKET_H
#define MARKET_H

#include "SubSystem.h"
#include "Inventory.h"

#include <string>

class Market : SubSystem
{
private:
	Inventory m_items;

public:
	Market(const std::string& id);

	virtual int Update() override;
};

#endif // MARKET_H
