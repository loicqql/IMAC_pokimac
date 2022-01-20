#pragma once
#include <string>
#include "Cell/Cell.h"

#define SIZE_MAP 20
#define VOID 0
#define GRASS 1

#define POKIMAC 3
#define HIDDEN_POKIMAC 4

#define POTION 5
#define HIDDEN_POTION 6

#define POKIBALL 7
#define HIDDEN_POKIBALL 8

#define DISPLAY_VOID '.'
#define DISPLAY_GRASS '#'
#define DISPLAY_PLAYER '@'

#define DISPLAY_POKIMAC 'P'
#define DISPLAY_HIDDEN_POKIMAC '#'

#define DISPLAY_POTION 'o'
#define DISPLAY_HIDDEN_POTION  '#'

#define DISPLAY_POKIBALL 'o'
#define DISPLAY_HIDDEN_POKIBALL '#'

#define NB_POKIS 10

#define NB_POTIONS 10

#define NB_POKIBALLS 10

using namespace std;

class Map {
	public:
		Map();

		void displayMap();

		char getDisplayByCoords(int x, int y);
		int getValueByCoords(int x, int y);
		void setValueByCoords(int x, int y, int value);
		Pokimac * getPokimacByCoords(int x, int y);
		

	private:
		int width = SIZE_MAP;
		int height = SIZE_MAP;
		Pokimac *pokis[NB_POKIS];
		Cell *tab[SIZE_MAP*SIZE_MAP];

		void setupGrass();
		void setupPokimacs();
		void setupItems();
};