#include <iostream>
#include <vector>
#include "include.h"
#include "monstermovement.h"
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
	cout << "hola1" << endl;//hola mis cojones

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

	char c, ant = '_';
	bool trobat = true;
	int movs = 0;

	while (cin >> c && trobat) {
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
					//CONSULTORI DISTANCIA//
					int diff1 = x - a;
					int diff2 = y - b;
					if (diff1 < 0) {
						diff1 = diff1 * -1;
					}
					if (diff2 < 0) {
						diff2 = diff2 * -1;
					}
					////////////////////////
					if (diff1 > diff2) {
						moveM_L(mat1, x, y, ant, trobat);
					}
					else if (diff1 < diff2) {
						moveM_U(mat1, x, y, ant, trobat);
					}
					else if (diff1 == diff2) {
						moveM_R(mat1, x, y, ant, trobat);
					}
				}
			}
			if (c == 'L') {
				moveT_L(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					//CONSULTORI DISTANCIA//
					int diff1 = x - a;
					int diff2 = y - b;
					if (diff1 < 0) {
						diff1 = diff1 * -1;
					}
					if (diff2 < 0) {
						diff2 = diff2 * -1;
					}
					////////////////////////
					if (diff1 < diff2) {
						moveM_U(mat1, x, y, ant, trobat);
					}
					else if (diff1 > diff2) {
						moveM_R(mat1, x, y, ant, trobat);
					}
					else if (diff1 == diff2) {
						moveM_L(mat1, x, y, ant, trobat);
					}
				}
			}
			if (c == 'R') {
				moveT_R(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					//CONSULTORI DISTANCIA//
					int diff1 = x - a;
					int diff2 = y - b;
					if (diff1 < 0) {
						diff1 = diff1 * -1;
					}
					if (diff2 < 0) {
						diff2 = diff2 * -1;
					}
					////////////////////////
					if (diff1 > diff2) {
						moveM_L(mat1, x, y, ant, trobat);
					}
					else if (diff1 < diff2) {
						moveM_R(mat1, x, y, ant, trobat);
					}
					else if (diff1 == diff2) {
						moveM_L(mat1, x, y, ant, trobat);
					}
				}
			}
			if (c == 'U') {
				moveT_U(mat1, a, b, trobat);
				if (movs % 2 == 0) {
					//CONSULTORI DISTANCIA//
					int diff1 = x - a;
					int diff2 = y - b;
					if (diff1 < 0) {
						diff1 = diff1 * -1;
					}
					if (diff2 < 0) {
						diff2 = diff2 * -1;
					}
					////////////////////////
					if (diff1 >= diff2) {
						moveM_U(mat1, x, y, ant, trobat);
					}
					else {
						moveM_L(mat1, x, y, ant, trobat);
					}
				}
			}
		}
		mapa(mat1, mat2, mat3);
	}
	return 0;
}