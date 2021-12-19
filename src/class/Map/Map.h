#pragma once
#include <string>
#include "Cell/Cell.h"

#define SIZE_MAP 20
#define VOID 0
#define GRASS 1
#define POKIMAC 3

#define DISPLAY_VOID '.'
#define DISPLAY_GRASS '#'
#define DISPLAY_PLAYER '@'
#define DISPLAY_POKIMAC 'P'


using namespace std;

class Map {
	public:
		Map();

		char getDisplayByCoords(int x, int y);

	private:
		int width = SIZE_MAP;
		int height = SIZE_MAP;
		Cell tab[SIZE_MAP*SIZE_MAP];
		int const tab_size = SIZE_MAP*SIZE_MAP;

		void initDisplay();
		void setupGrass();
		void setupPokimacs();
};