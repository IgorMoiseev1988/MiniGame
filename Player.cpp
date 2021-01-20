#include "Player.h"
#include "ColorPrint.h"

extern const int g_deley;

Player::Player(name_t& name, int difficalt_lvl)
	: Creature(name, 10.0, 1, 0, 0)
	, level(1)
	, godMode(false) {
	if (name == "GOD") {
		godMode = true;
		m_atk = 100;
		m_health = 1000;
	}
	switch (difficalt_lvl) {
	case 1:  m_atk_multi = 2.0; break;
	case 2:  m_atk_multi = 1.5; break;
	case 3:  m_atk_multi = 1.0; break;
	case 4:  m_atk_multi = 0.8; break;
	case 5:  m_atk_multi = 0.5; break;
	default: m_atk_multi = 1.0; break;
	}
}

double Player::getAtkMulti() const {
	return m_atk_multi;
}

double Player::getAtk() const {
	return m_atk * m_atk_multi;
}

int Player::getExpLeft() const{
	return 12 * level - m_exp;
}

int Player::getLevel() const {
	return level;
}

bool Player::hasWon() const {
	return level > 19;
}

void Player::levelUp() {
	++level;
	++m_atk;
	if (godMode) m_atk = 100;
	m_health = max_health(level);
	levelUpMsg();
}

void Player::addExp(int exp) {
	m_exp += exp;
	if (m_exp >= 12 * level) {
		m_exp -= 12 * level;
		levelUp();
	}
}

//private

double Player::max_health(int level) {
	if (godMode) return 1000;
	switch (level) {
	case 1:  return 10.0;
	case 2:  return 11.0;
	case 3:  return 13.0;
	case 4:  return 16.0;
	case 5:  return 20.0;
	case 6:  return 25.0;
	case 7:  return 31.0;
	case 8:  return 38.0;
	case 9:  return 46.0;
	case 10: return 55.0;
	case 11: return 65.0;
	case 12: return 76.0;
	case 13: return 88.0;
	case 14: return 101.0;
	case 15: return 115.0;
	case 16: return 130.0;
	case 17: return 146.0;
	case 18: return 163.0;
	case 19: return 181.0;
	case 20: return 210.0;
	}
	return 1000.0;
}

void Player::levelUpMsg() const {
	std::cout << ColorPrint("Ты получил " + std::to_string(level) + " уровень!", Colors::Level) << "\n";
	Sleep(g_deley);
	std::cout << ColorPrint("Здоровье восстановлено. Максимум здоровья " + std::to_string(static_cast<int>(m_health)), Colors::Health) << "\n";
}