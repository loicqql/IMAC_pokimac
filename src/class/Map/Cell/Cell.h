#pragma once
using namespace std;
#include "../../Pokimac/Pokimac.h"

class Cell {
	public:
		Cell();

		int getValue();
    void setValue(int new_value);
    void setPokimac(int index);
    int getPokimac();

	private:
    int value;
		int indexPoki;
};