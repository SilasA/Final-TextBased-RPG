#include "Market.h"

Market::Market(const std::string& id) :
	SubSystem(id), m_items(std::vector<Item>{
		// Shop items
	})
{
}

	int Market::Update()
	{
		return 0;
	}
