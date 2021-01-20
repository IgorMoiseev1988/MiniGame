// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <string>
#include <Windows.h>


#include "Game.h"


//TODO write class GAME, think about crossplatfor Sleep and COLORS

extern const int g_deley(300);



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game new_game;
	new_game.Start();
	char c = getchar();
	return 0;
}