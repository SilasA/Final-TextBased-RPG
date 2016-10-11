#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"

// 
class MenuState : public GameState
{
	typedef void(MenuState::*Function)(void);
	typedef std::map<std::string, Function>::iterator Option;
private:
	std::map<std::string, Function> m_options;

	Option interaction();

public:
	MenuState(const std::string& id);

	virtual void Update() override;
};

#endif // MENU_STATE_H
