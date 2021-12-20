#pragma once
#include <string>
#include "Cell/Cell.h"

#define SIZE_MAP 20
#define VOID 0
#define GRASS 1
#define POKIMAC 3
#define HIDDEN_POKIMAC 4

#define DISPLAY_VOID '.'
#define DISPLAY_GRASS '#'
#define DISPLAY_PLAYER '@'
#define DISPLAY_POKIMAC 'P'
#define DISPLAY_HIDDEN_POKIMAC '#'


using namespace std;

class Map {
	public:
		Map();

		void displayMap();

		char getDisplayByCoords(int x, int y);
		int getValueByCoords(int x, int y);
		Pokimac * getPokimacByCoords(int x, int y);
		

	private:
		int width = SIZE_MAP;
		int height = SIZE_MAP;
		Cell tab[SIZE_MAP*SIZE_MAP];
		int const tab_size = SIZE_MAP*SIZE_MAP;

		void setupGrass();
		void setupPokimacs();
};