#pragma once
using namespace std;
#include "../../Pokimac/Pokimac.h"

class Cell {
	public:
		Cell();

		int getValue();
    void setValue(int new_value);
    void setPokimac(Pokimac *p_pokimac);
    Pokimac getPokimac();

	private:
    int value;
		Pokimac *poki;
};