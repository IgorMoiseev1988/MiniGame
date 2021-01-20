#ifndef CREATURE_H
#define CREATURE_H

#include <string>
using name_t = const std::string;

class Creature {
protected:
	std::string m_name;
	double m_health;
	double m_atk;
	int m_gold;
	int m_exp;
public:
	explicit Creature(name_t& name = "Noname", double health = 10.0, double atk = 1.0, int gold = 0, int exp = 0);
	name_t& getName()   const;
	double  getHealth() const;
	double  getAtk()    const;
	int     getGold()   const;
	int     getExp()    const;

	void reduceHealth(double val);
	bool isDead();
	void addGold(int val);
};

#endif