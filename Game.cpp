#include "Game.h"
#include "ColorPrint.h"

extern const int g_deley;

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Game::Game() 
	: difficalt_lvl(3)
	, chance_left_fail(50) { }


void Game::Start() {
	srand(static_cast<unsigned int>(time(0)));
	rand();
	std::string name = askName();
	std::cout << "Добро пожаловать, " << name << "\n";
	difficalt_lvl = getLevel();
	player = Player(name, difficalt_lvl);
	chance_left_fail = 50 + (difficalt_lvl - 3) * 20;
	std::cout << "\nУ тебя " << ColorPrint(player.getHealth(), Colors::Health) << " здоровья. Твоя атака всегда равна уровню * " << ColorPrint(player.getAtkMulti(), Colors::Damage) << "\n";

	while (!player.isDead() && !player.hasWon()) {
		monster = Monster::getRandomMonster(player.getLevel());
		FightWithMonser();
	}
	if (player.isDead()) {
		std::cout << "\nТвоя никчемная жизнь завершена. Твой посмертный уровень " << ColorPrint(player.getLevel(), Colors::Level) 
			<< ".\nТвои " << ColorPrint(player.getGold(), Colors::Gold) << " золота пойдут на компенсацию семьям погибших от твоей руки монстров.\n";
	} else {
		std::cout << "Ты достиг 20-ого уровня и заработал " << ColorPrint(player.getGold(), Colors::Gold) << " золота. Можешь пойти попить чаю, " << ColorPrint("УБИЙЦА!!!", Colors::Murder) << "\n";
	}
}

void Game::attackMonster() {
	player.reduceHealth(monster.getAtk());
	std::cout << ColorPrint(monster.getName(), Colors::Monster) << " наносит тебе " << ColorPrint(monster.getAtk(), Colors::Damage) << " урона" << "\n";
	Sleep(g_deley);
}

void Game::attackPlayer() {
	monster.reduceHealth(player.getAtk());
	std::cout << "Ты наносишь " << ColorPrint(monster.getName() + "у", Colors::Monster) << ColorPrint(player.getAtk(), Colors::Damage) << " урона\n";
	Sleep(g_deley);
}

void Game::FightWithMonser() {
	std::cout << "\nТы встретил " << ColorPrint(monster.getName() + "а", Colors::Monster) << ".\n";
	while (!player.isDead() && !monster.isDead()) {
		monsterFightInitMsg();
		char choise = getChoise();
		Sleep(g_deley);
		if (choise == 2) {
			if (tryEscaped()) return;
			attackMonster();
		} else {
			attackPlayer();
			if (monster.isDead()) {
				monsterDeadAction();
			} else {
				attackMonster();
			}
		}
	}
}

int Game::getNumber(int max, const std::string& hint) const {
	int i = 0;
	do {
		std::cout << hint;
		std::cin >> i;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			i = 0;
		}
		std::cin.ignore(32767, '\n');
	} while (i < 1 || i > max);
	return i;
}

int Game::getLevel() const {
	return getNumber(5, "1 - Изи\n2 - Легко\n3 - Норм\n4 - Сложна\n5 - Анрил\nВыбери уровень сложности: ");
}

int Game::getChoise() const {
	return getNumber(2, "(1)Атаковать, (2)Сбежать: ");
}

std::string Game::askName() const {
	std::cout << "Введи имя: ";
	std::string name;
	std::cin >> name;
	return name;
}

bool Game::tryEscaped() {
	int chance = getRandomNumber(1, 100);
	if (chance > chance_left_fail) {
		std::cout << "\nТы трусливо " << ColorPrint("Сбежал.", Colors::Run) << "\n";
		std::cout << "--------------------------------------\n";
		Sleep(g_deley);
		return true;
	}
	std::cout << ColorPrint("Сбежать не удалось!!!", Colors::Run) << "\n";
	return false;
}

void Game::monsterFightInitMsg() {
	std::cout << "\nЗдоровье: " << player.getName();
	std::cout << "(" << ColorPrint(std::to_string(player.getLevel()) + " lvl", Colors::Level) << "): ";
	std::cout << ColorPrint(player.getHealth(), Colors::Health) << ", " << ColorPrint(monster.getName(), Colors::Monster);
	std::cout << "(" << ColorPrint(std::to_string(static_cast<int>(monster.getAtk())) + " lvl", Colors::Level) << "): ";
	std::cout << ColorPrint(monster.getHealth(), Colors::Health) << "\n";
}

void Game::monsterDeadAction() {
	std::cout << "Ты " << ColorPrint("убил", Colors::Murder) << " будного " << ColorPrint(monster.getName() + "a", Colors::Monster) << "\n";
	Sleep(g_deley);
	player.addGold(monster.getGold());
	std::cout << "Получено " << ColorPrint(monster.getExp(), Colors::Exp) << " опыта и " << ColorPrint(monster.getGold(), Colors::Gold) << " золота\n";
	Sleep(g_deley);
	player.addExp(monster.getExp());
	std::cout << "До следующего уровня осталось " << ColorPrint(player.getExpLeft(), Colors::Exp) << " ед.опыта\n";
	std::cout << "--------------------------------------\n";
	Sleep(g_deley);
}
