#include <iostream>
#include <vector>
#include "mapa.h"
#include "monsterpathfind.h"
#include "playermovement.h"

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> mat1(n, vector<char>(m));
	vector<vector<bool>> mat2(n, vector<bool>(m, false));
	vector<vector<char>> mat3(n, vector<char>(m, '.'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat1[i][j];
		}
	}
	int a, b, x, y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] == 'T') {
				a = i;
				b = j;
				mat2[i][j] = true;
			}
			if (mat1[i][j] == 'M') {
				x = i;
				y = j;
			}
			if (mat1[i][j] == 'S') {
				mat2[i][j] = true;
			}
		}
	}

	mapa(mat1, mat2, mat3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat3[i][j];
		}
		cout << endl;
	}

	char c;
	char ant = '_';
	bool trobat = true;
	int movs = 0;
	bool toggleMonsterVision = false;

	while (cin >> c && trobat) {
		if (toggleMonsterVision == false && mat1[x][y] == 'T' && mat2[x][y] == true) {	//starts minotaur movement when revealed by player
			toggleMonsterVision = true;
		}
		if (c == 'S') {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << mat3[i][j];
				}
				cout << endl;
			}
		}
		else if (c == 'Z') {
			cout << "A reveure!" << endl;
			cout << "Has fet " << movs << " moviments." << endl;
			trobat = false;
		}
		else {
			movs++;
			if (c == 'D') {
				moveT_D(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					monsterpath(mat1, x, y, ant, trobat, a, b);
				}
			}
			if (c == 'L') {
				moveT_L(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					monsterpath(mat1, x, y, ant, trobat, a, b);
				}
			}
			if (c == 'R') {
				moveT_R(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					monsterpath(mat1, x, y, ant, trobat, a, b);
				}
			}
			if (c == 'U') {
				moveT_U(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					monsterpath(mat1, x, y, ant, trobat, a, b);
				}
			}
		}
	mapa(mat1, mat2, mat3);
	}
	return 0;
}
