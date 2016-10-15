#ifndef LOGGER_H
#define LOGGER_H


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Time.h"

#define LOG_DIV "===================================================================================================="
#define IDEAL_SENDER_L 6

// Type of log
enum class LogType {
	kERROR,		// If the program can't run
	kWARNING,	// If the program can run but something might or has gone wrong
	kINFO,		// IF the log is just for info i.e. Debugging
	kALL		// For global logs (Log to all files)
};

// For iteration over the log map
typedef std::map<std::string, std::ofstream>::iterator FItr_t;

// Static class for managing and writing multiple log files
class Logger
{
private:
	// To create timestamps for each log
	static Time time;

	// Map containing all log files with IDs
	static std::map<std::string, std::ofstream> m_fsout;

	// Writes an already formatted string to all open log files
	static void writetoall(std::string& log);

	static bool exists(std::string& log);

public:

	Logger();
	~Logger();

	// Adds a log file to the map
	// Returns if it was a success or not
	static bool AddLogger(std::string&& id, std::string&& filename);

	// Closes the IDed log file
	// returns if the 'to be closed' file exists and closure was successful
	static bool CloseLogger(std::string& id);

	// Closes all log files
	static void CloseAll();

	// Erases all closed log files
	static void EraseAllClosed();

	// Closes all files then erases them
	static void EraseAll();

	// Writes a log to the IDed file
	// NOTE: ID must be provided if the log isn't intended for all files
	static bool WriteLog(std::string tag, std::string content, std::string id = ""); 
};

#endif // LOGGER_H
