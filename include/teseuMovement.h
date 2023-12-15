#pragma once

// Player movement function
void moveTeseu(vector<vector<char>>& currentMap, int& a, int& b, char direction, bool& isGameActive, int& movs) {
	int n = currentMap.size();
	int m = currentMap[0].size();
	int newA = a, newB = b;

	// Determine the new position based on the direction
	if (direction == 'U') {
		newA = max(a - 1, 0);
	}
	else if (direction == 'D') {
		newA = min(a + 1, n - 1);
	}
	else if (direction == 'L') {
		newB = max(b - 1, 0);
	}
	else if (direction == 'R') {
		newB = min(b + 1, m - 1);
	}

	// Check the content of the new position and act accordingly
	if (currentMap[newA][newB] == 'S') {
		cout << "Felicitats has arribat a la sortida!!" << endl;
		cout << "Has fet " << movs << " moviments" << endl;
		isGameActive = false;
	}
	else if (currentMap[newA][newB] == 'M') {
		cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
		isGameActive = false;
	}
	else if (currentMap[newA][newB] == '_') {
		currentMap[a][b] = '_'; // Clear the old position
		a = newA;
		b = newB;
		currentMap[a][b] = 'T'; // Set the new position
	}
}