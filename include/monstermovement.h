#pragma once
#include <iostream>
#include <vector>

using namespace std;

void moveM_D(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat) {
	//monstermove DOWN
	int n = mat1.size();
	if (x + 1 < n) {
		if (mat1[x + 1][y] == 'T') {
			cout << "Has perdut! El Minotaure t’ha atrapat!" << endl;
			trobat = false;
		}
		mat1[x][y] = ant;
		ant = mat1[x + 1][y];
		mat1[x + 1][y] = 'M';
		cout << "MONSTERDOWN";//test
	}

}

void moveM_U(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat) {
	//monstermove UP
	if (x - 1 >= 0) {
		if (mat1[x - 1][y] == 'T') {
			cout << "Has perdut! El Minotaure t’ha atrapat!" << endl;
			trobat = false;
		}
		mat1[x][y] = ant;
		ant = mat1[x - 1][y];
		mat1[x - 1][y] = 'M';
		cout << "MONSTERUP";//test
	}

}

void moveM_L(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat) {
	//monstermove LEFT
	if (y - 1 >= 0) {
		if (mat1[x][y - 1] == 'T') {
			cout << "Has perdut! El Minotaure t’ha atrapat!" << endl;
			trobat = false;
		}
		mat1[x][y] = ant;
		ant = mat1[x][y - 1];
		mat1[x][y - 1] = 'M';
		cout << "MONSTERLEFT";//test
	}
}

void moveM_R(vector<vector<char>>& mat1, int& x, int& y, char& ant, bool& trobat) {
	//monstermove RIGHT
	int m = mat1[0].size();
	if (y + 1 < m) {
		if (mat1[x][y + 1] == 'T') {
			cout << "Has perdut! El Minotaure t’ha atrapat!" << endl;
			trobat = false;
		}
		mat1[x][y] = ant;
		ant = mat1[x][y + 1];
		mat1[x][y + 1] = 'M';
		cout << "MONSTERRIGHT";//test
	}
}

