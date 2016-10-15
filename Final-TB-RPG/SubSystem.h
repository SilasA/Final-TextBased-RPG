#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "Utilities\Logger.h"

#include <string>
#include <cstdlib>
#include <thread>

// Macros for some tasks
#define CLEAR system("cls")
#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms))

// Abstract for every subsystem in the program
class SubSystem
{
protected:
	// Subsystem id used to identify it in logs
	std::string m_id;

	// Constructs id; Log initialization
	SubSystem(const std::string& id) : 
		m_id(id)
	{
		Logger::WriteLog(m_id, "Initialized");
	}

public:
	// Used as the subsystem's main()
	virtual int Run() = 0;

	// Gets subsystem id
	inline std::string ID() { return m_id; }
};

#endif // SUBSYSTEM_H

