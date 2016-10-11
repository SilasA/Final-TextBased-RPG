#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"

#include <string>

//
class BattleState : public GameState
{
private:


public:
	BattleState(const std::string& id);

	virtual void Update() override;
};

#endif // BATTLE_STATE_H
