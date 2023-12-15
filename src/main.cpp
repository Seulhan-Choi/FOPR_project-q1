#include <iostream>
#include <vector>
#include "matrixUpdate.h"
#include "minotaurPathfind.h"
#include "teseuMovement.h"

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> currentMap(n, vector<char>(m));
	vector<vector<bool>> visibilityMap(n, vector<bool>(m, false));
	vector<vector<char>> displayedMap(n, vector<char>(m, '.'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> currentMap[i][j];
		}
	}
	int a, b, x, y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (currentMap[i][j] == 'T') {
				a = i;
				b = j;
				visibilityMap[i][j] = true;
			}
			if (currentMap[i][j] == 'M') {
				x = i;
				y = j;
			}
			if (currentMap[i][j] == 'S') {
				visibilityMap[i][j] = true;
			}
		}
	}

	updateVisibilityMatrix(currentMap, visibilityMap, displayedMap);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << displayedMap[i][j];
		}
		cout << endl;
	}
	cout << endl;

	char c;
	char previousCell = '_';
	bool isGameActive = true;
	int movs = 0;
	bool toggleMonsterVision = false;

	while (cin >> c && isGameActive) {
		if (toggleMonsterVision == false && visibilityMap[x][y] == true) {	//starts minotaur movement when revealed by player
			toggleMonsterVision = true;
		}
		if (c == 'S') {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << displayedMap[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (c == 'Z') {
			cout << "A reveure!" << endl;
			cout << "Has fet " << movs << " moviments" << endl;
			isGameActive = false;
		}
		else {
			movs++;
			if (c == 'D') {
				moveTeseu(currentMap, a, b, 'D', isGameActive, movs);
				if (movs % 2 == 1 && isGameActive) {
					minotaurPath(currentMap, x, y, previousCell, isGameActive, a, b, toggleMonsterVision);
				}
			}
			if (c == 'L') {
				moveTeseu(currentMap, a, b, 'L', isGameActive, movs);
				if (movs % 2 == 1 && isGameActive) {
					minotaurPath(currentMap, x, y, previousCell, isGameActive, a, b, toggleMonsterVision);
				}
			}
			if (c == 'R') {
				moveTeseu(currentMap, a, b, 'R', isGameActive, movs);
				if (movs % 2 == 1 && isGameActive) {
					minotaurPath(currentMap, x, y, previousCell, isGameActive, a, b, toggleMonsterVision);
				}
			}
			if (c == 'U') {
				moveTeseu(currentMap, a, b, 'U', isGameActive, movs);
				if (movs % 2 == 1 && isGameActive) {
					minotaurPath(currentMap, x, y, previousCell, isGameActive, a, b, toggleMonsterVision);
				}
			}
		}
		updateVisibilityMatrix(currentMap, visibilityMap, displayedMap);
	}
	return 0;
}
