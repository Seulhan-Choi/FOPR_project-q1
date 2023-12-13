#pragma once
#include <iostream>
#include <vector>
#include "monstermovement.h"

using namespace std;

//CONSULTORI DISTANCIA
void monsterpath(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat, int& a, int& b ) {
	int diff1 = x - a;
	int diff2 = y - b;


	if (diff1 > 0 && diff2 > 0) {
		if (diff1 == diff2 || diff1 < diff2)	moveM_L(mat1, x, y, ant, trobat);
		else
		{
			moveM_D(mat1, x, y, ant, trobat);
		}
	}
	else if (diff1 > 0 && diff2 < 0) {
		if (diff1 == diff2 || diff1 < diff2)	moveM_L(mat1, x, y, ant, trobat);
		else
		{
			moveM_U(mat1, x, y, ant, trobat);
		}
	}
	else if (diff1 < 0 && diff2 < 0) {
		if (diff1 == diff2 || diff1 < diff2)	moveM_R(mat1, x, y, ant, trobat);
		else
		{
			moveM_U(mat1, x, y, ant, trobat);
		}
	}
	else if (diff1 < 0 && diff2 < 0) {
		if (diff1 == diff2 || diff1 < diff2)	moveM_R(mat1, x, y, ant, trobat);
		else
		{
			moveM_D(mat1, x, y, ant, trobat);
		}
	}
}
