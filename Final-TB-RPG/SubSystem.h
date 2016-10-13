#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "Utilities\Logger.h"

#include <string>
#include <cstdlib>
#include <thread>

#define CLEAR system("cls")
#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms))

// Abstract for every subsystem in the program
class SubSystem
{
protected:
	std::string m_id;

	SubSystem(const std::string& id) : 
		m_id(id)
	{
		Logger::WriteLog(m_id, "Initialized");
	}

public:
	virtual int Update() = 0;

	inline std::string ID() { return m_id; }
};

#endif // SUBSYSTEM_H

