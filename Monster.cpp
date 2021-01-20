#include "Monster.h"

Monster::Monster(Monster::Types type) :
		Creature(monsterData[static_cast<int>(type)].name,
				 monsterData[static_cast<int>(type)].health,
				 monsterData[static_cast<int>(type)].atk,
				 monsterData[static_cast<int>(type)].gold,
				 monsterData[static_cast<int>(type)].exp)
{ }

Monster Monster::getRandomMonster(int level) {
	int min = 0, max = 0;
	switch (level) {
	case 1:  min = 0; max = 0; break;
	case 2:  min = 0; max = 1; break;
	case 3:  min = 0; max = 1; break;
	case 4:  min = 0; max = 1; break;
	case 5:  min = 1; max = 2; break;
	case 6:  min = 1; max = 2; break;
	case 7:  min = 1; max = 2; break;
	case 8:  min = 1; max = 2; break;
	case 9:  min = 1; max = 3; break;
	case 10: min = 1; max = 3; break;
	case 11: min = 1; max = 4; break;
	case 12: min = 1; max = 4; break;
	case 13: min = 2; max = 4; break;
	case 14: min = 2; max = 4; break;
	case 15: min = 2; max = 4; break;
	case 16: min = 3; max = 4; break;
	case 17: min = 3; max = 4; break;
	case 18: min = 3; max = 4; break;
	case 19: min = 4; max = 4; break;
	case 20: min = 4; max = 4; break;
	}
	return Monster(static_cast<Monster::Types>(getRandomNumber(min, max)));
}

Monster::MonsterData Monster::monsterData[static_cast<int>(Monster::Types::MAX_TYPES)] {
	{"лох", 1.0, 1.0, 1, 10},
	{"скелет", 6.0, 2.0, 5, 30},
	{"орк", 18.0, 5.0, 25, 60},
	{"огр", 36.0, 10.0, 100, 100},
	{"дракон", 100.0, 20.0, 1000, 200}
};

