#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#elif defined(linux) || defined(__linux)
//todo includes for linux
#endif

extern const int g_deley;

enum class Colors {
	Exp = 1,
	Health = 2,
	Damage = 4,
	Level = 5,
	Gold = 6,
	Normal = 7,
	Monster = 11,
	Murder = 12,
	Run = 13,
};

class ColorPrint{
public:
	template <typename T>
	ColorPrint(const T& t, Colors color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, static_cast<int>(color));
		std::cout << t;
		SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::Normal));
	}
	friend std::ostream& operator<<(std::ostream&, const ColorPrint&);
};





#endif
