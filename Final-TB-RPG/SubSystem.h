#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include <string>

// Abstract for every subsystem in the program
class SubSystem
{
protected:
	static int instanceCount;

	std::string m_id;

	SubSystem(const std::string& id) : 
		m_id(id)
	{
		instanceCount++;
	}

public:
	virtual void Update() = 0;

	inline std::string ID() { return m_id; }
};

int SubSystem::instanceCount = 0;

#endif // SUBSYSTEM_H

