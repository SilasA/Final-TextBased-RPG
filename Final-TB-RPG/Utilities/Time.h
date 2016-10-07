#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>

class Time
{
private:

	time_t t;
	struct tm now;

public:

	// Returns the date + time in MM/DD/YYYY HH:MM:SS format
	std::string getDateTime()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_mon + 1) + "/" +
			std::to_string(now.tm_mday) + "/" +
			std::to_string(now.tm_year + 1900) + " " +
			std::to_string(now.tm_hour) + ":" +
			std::to_string(now.tm_min) + ":" +
			std::to_string(now.tm_sec) + "]";
	}

	// Returns the date in MM/DD/YYYY format
	std::string getDate()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_mon + 1) + "/" +
			std::to_string(now.tm_mday) + "/" +
			std::to_string(now.tm_year + 1900) + "]";
	}

	// Returns the time in HH:MM:SS format
	std::string getTime()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_hour) + ":" +
			std::to_string(now.tm_min) + ":" +
			std::to_string(now.tm_sec) + "]";
	}
};

#endif // TIME_H