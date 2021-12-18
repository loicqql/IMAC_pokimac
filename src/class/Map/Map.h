#pragma once
#include <string>

#define SIZE_MAP 20
#define VOID 0
#define GRASS 1
#define POKIMAC 3

#define DISPLAY_VOID '.'
#define DISPLAY_GRASS '#'
#define DISPLAY_PLAYER 'P'
#define DISPLAY_POKIMAC 'I'


using namespace std;

class Map {
	public:
		Map();

		char getDisplayByCoords(int x, int y);

	private:
		int width = SIZE_MAP;
		int height = SIZE_MAP;
		int tab[SIZE_MAP*SIZE_MAP];
		int const tab_size = SIZE_MAP*SIZE_MAP;

		void initDisplay();
		void setupGrass();
};