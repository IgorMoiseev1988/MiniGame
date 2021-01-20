#include "Creature.h"

Creature::Creature(name_t& name, double health, double atk, int gold, int exp)
		: m_name(name)
		, m_health(health)
		, m_atk(atk)
		, m_gold(gold)
		, m_exp(exp) 
{ }

name_t& Creature::getName() const {
	return m_name;
}

double Creature::getHealth() const {
	return m_health;
}

double Creature::getAtk() const {
	return m_atk;
}

int Creature::getGold() const {
	return m_gold;
}

int Creature::getExp() const {
	return m_exp;
}

void Creature::reduceHealth(double val) {
	m_health -= val;
}

bool Creature::isDead() {
	return m_health <= 0;
}

void Creature::addGold(int val) {
	m_gold += val;
}
