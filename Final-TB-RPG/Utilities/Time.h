#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>

// Class for fetching time in different formats
class Time
{
private:

	time_t t;
	struct tm now;

public:

	// Returns the date + time in MM/DD/YYYY HH:MM:SS format
	std::string GetDateTime()
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

	// Returns the date + time in MM-DD-YYYY HH-MM-SS format
	// Safe for filenames
	std::string GetSafeDateTime()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_mon + 1) + "-" +
			std::to_string(now.tm_mday) + "-" +
			std::to_string(now.tm_year + 1900) + " " +
			std::to_string(now.tm_hour) + "-" +
			std::to_string(now.tm_min) + "-" +
			std::to_string(now.tm_sec) + "]";
	}

	// Returns the date in MM/DD/YYYY format
	std::string GetDate()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_mon + 1) + "/" +
			std::to_string(now.tm_mday) + "/" +
			std::to_string(now.tm_year + 1900) + "]";
	}

	// Returns the time in HH:MM:SS format
	std::string GetTime()
	{
		t = time(NULL);
		localtime_s(&now, &t);
		return "[" +
			std::to_string(now.tm_hour) + ":" +
			std::to_string(now.tm_min) + ":" +
			std::to_string(now.tm_sec) + "]";
	}

	// Returns current system time in seconds
	double GetTimeSec() 
	{
		return time(NULL);
	}
};

// Class for managing time
class Timer
{
private:
	bool m_running;
	double m_timeElapsed;
	double m_startTime;

	Time m_time;

public:
	Timer()
	{
		m_timeElapsed = 0;
		m_startTime = 0;
	}

	void Start()
	{
		m_running = true;
		m_startTime = m_time.GetTimeSec();
	}

	void Stop()
	{
		m_running = false;
	}

	void Reset()
	{
		m_timeElapsed = 0;
		m_startTime = 0;
	}

	double GetTimeElapsed()
	{
		m_timeElapsed = m_time.GetTimeSec() - m_startTime;
		return m_timeElapsed;
	}
};

#endif // TIME_H