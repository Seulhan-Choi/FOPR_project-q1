#pragma once
#include <iostream>
#include <vector>
#include "monstermovement.h"

using namespace std;

//CONSULTORI DISTANCIA
void monsterpath(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat, int& a, int& b ) {
	int dif1 = x - a;
	int dif2 = y - b;


	if (dif1 < 0 && dif2 > 0) {
		if (dif1 == dif2 || dif1 < dif2)	moveM_L(mat1, x, y, ant, trobat);
		else
		{
			moveM_D(mat1, x, y, ant, trobat);
			cout << "TEST"; //test
		}
	}
	else if (dif1 > 0 && dif2 > 0) {
		if (dif1 == dif2 || dif1 < dif2)	moveM_L(mat1, x, y, ant, trobat);
		else
		{
			moveM_U(mat1, x, y, ant, trobat);
			cout << "TEST"; //test
		}
	}
	else if (dif1 > 0 && dif2 < 0) {
		if (dif1 == dif2 || dif1 < dif2)	moveM_R(mat1, x, y, ant, trobat);
		else
		{
			moveM_U(mat1, x, y, ant, trobat);
			cout << "TEST"; //test
		}
	}
	else if (dif1 < 0 && dif2 < 0) {
		if (dif1 == dif2 || dif1 < dif2)	moveM_R(mat1, x, y, ant, trobat);
		else
		{
			moveM_D(mat1, x, y, ant, trobat);
			cout << "TEST"; //test
		}
	}
}
