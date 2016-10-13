#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"

// 
class MenuState : public GameState
{
	typedef void(*Function)(Game*);
	typedef std::map<std::string, Function>::iterator Option;
private:
	std::map<std::string, Function> m_options;

	std::string interaction();

public:
	MenuState(Game* game, const std::string& id);

	virtual int Update() override;
};

#endif // MENU_STATE_H
