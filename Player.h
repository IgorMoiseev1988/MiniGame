#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> //std::cout
#include <Windows.h> //Sleep
#include "Creature.h"

class Player : public Creature {
public:
	explicit Player(name_t& name = "Unknown", int difficalt_lvl = 3);
	double getAtkMulti() const;
	double getAtk()      const;
	int    getExpLeft()  const;
	int    getLevel()    const;
	 
	bool hasWon() const;
	void levelUp();
	void addExp(int);
private:
	int level;
	bool godMode;
	double m_atk_multi;
	double max_health(int);
	void levelUpMsg() const;
};

#endif
