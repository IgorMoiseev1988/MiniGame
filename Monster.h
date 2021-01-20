#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

int getRandomNumber(int, int);

class Monster : public Creature {
public:
	enum class Types {
		SLIME,
		SKELETON,
		ORC,
		OGRE,
		DRAGON,
		MAX_TYPES,
	};
	explicit Monster(Monster::Types type = Monster::Types::SLIME);
	static Monster getRandomMonster(int level);
private:
	struct MonsterData {
		std::string name;
		double health;
		double atk;
		int gold;
		int exp;
	};
	static MonsterData monsterData[static_cast<int>(Monster::Types::MAX_TYPES)];
};

#endif