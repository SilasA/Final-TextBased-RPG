// Final-TB-RPG.cpp : Defines the entry point for the console application.
//

///////////////////////////////////////////////////////////////////////////////
// FOR WINDOWS ONLY
///////////////////////////////////////////////////////////////////////////////

#include "Utilities\Logger.h"
#include "Game.h"

#include <direct.h>

int main(int argc, char* argv[])
{
	// Add "gibmonis" as an arguement to give unlimited monis

	_mkdir("./Logs");
	Logger::AddLogger("log", "./Logs/log");
	Logger::WriteLog("Main", "Program started");
	Game game("Game");
	game.Run();
	Logger::WriteLog("Main", "Program terminated");
    return 0;
}

