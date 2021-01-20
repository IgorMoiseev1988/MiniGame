#ifndef GAME_H
#define GAME_H

#include <ctime>

#include "Player.h"
#include "Monster.h"
//#include "ConsoleOutput.h"

int getRandomNumber(int min, int max);

class Game {
public:
	Game();
	void Start();
	
private:
	Player player;
	Monster monster;

	void attackMonster();
	void attackPlayer();
	void FightWithMonser();

	int difficalt_lvl;
	int chance_left_fail;

	int getNumber(int, const std::string&) const;
	int getLevel() const;
	int getChoise() const;
	std::string askName() const;
	bool tryEscaped();
	void monsterFightInitMsg();
	void monsterDeadAction();
};

#endif
