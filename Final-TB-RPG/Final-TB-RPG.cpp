// Final-TB-RPG.cpp : Defines the entry point for the console application.
//

#include "Utilities\Logger.h"
#include <windows.h>
#include <cstdlib>
//TODO: 
// -


int main(int argc, char* argv[])
{
	Logger::AddLogger("log", "./Log/log.txt");
	Logger::WriteLog("Main", "Program started");

    return 0;
}

