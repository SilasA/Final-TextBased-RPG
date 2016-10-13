#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "Utilities\Logger.h"
#include "GameState.h"
#include "Player.h"

#include <string>

// Controls battle functionality
class BattleState : public GameState
{
private:
	Player* m_first;
	Player* m_second;

public:
	BattleState(Game* game, const std::string& id, Player* first, Player* second);

	virtual int Update() override;

	inline Player* First() { return m_first; }
	inline Player* Second() { return m_second; }
};

#endif // BATTLE_STATE_H
