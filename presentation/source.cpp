#include <iostream>
#include <vector>

using namespace std;

// Reveals the cells surrounding the given position of the player(Teseu) (row, col) in the currentMap.
// This is used to update the visibility around the player's position.
// This looping mechanism is designed to be flexible and adaptable to different positions of 'T' in the matrix.
void revealSurroundingArea(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, int row, int col) {
	int n = currentMap.size();
	int m = currentMap[0].size();

	// Iterate over a 3x3 area centered around (row, col)
	for (int i = max(0, row - 1); i <= min(row + 1, n - 1); ++i) {
		for (int j = max(0, col - 1); j <= min(col + 1, m - 1); ++j) {
			visibilityMap[i][j] = true; // Set the visibility of this cell to true
		}
	}
}

// Updates the displayedMap based on the currentMap and visibilityMap.
// Only cells that are visible in the visibilityMap are updated in the displayedMap.
void updateDisplayedMap(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, vector<vector<char>>& displayedMap) {
	int n = currentMap.size();
	int m = currentMap[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// Check if the current cell is visible
			if (visibilityMap[i][j]) {
				// Update the displayedMap: convert '_' in currentMap to ' ' in displayedMap
				if (currentMap[i][j] == '_') {
					displayedMap[i][j] = ' '; // Replace underscore with space
				}
				else {
					displayedMap[i][j] = currentMap[i][j]; // Keep the original character
				}
			}
		}
	}
}

// Main function to update the visibility of the map.
// This function iterates over the currentMap to find the player's position and updates
// the visibility and displayed map accordingly.
void updateVisibilityMatrix(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, vector<vector<char>>& displayedMap) {
	int n = currentMap.size();
	int m = currentMap[0].size();

	// Iterate over the entire currentMap to find the player's position
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// When the player's position is found, reveal the surrounding area
			if (currentMap[i][j] == 'T') {
				revealSurroundingArea(currentMap, visibilityMap, i, j);
			}
		}
	}

	// Update the displayed map based on the current visibility
	updateDisplayedMap(currentMap, visibilityMap, displayedMap);
}

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

// Minotaur movement function
void moveMinotaur(vector<vector<char>>& currentMap, int& x, int& y, char direction, char& previousCell, bool& isGameActive) {
	int n = currentMap.size();
	int m = currentMap[0].size();
	int newX = x, newY = y;

	// Determine the new position based on the direction
	if (direction == 'U') {
		newX = max(x - 1, 0);
	}
	else if (direction == 'D') {
		newX = min(x + 1, n - 1);
	}
	else if (direction == 'L') {
		newY = max(y - 1, 0);
	}
	else if (direction == 'R') {
		newY = min(y + 1, m - 1);
	}

	// Check the content of the new position and act accordingly
	if (currentMap[newX][newY] == 'T') {
		cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
		isGameActive = false;
	}
	else {
		// Update the Minotaur's position
		currentMap[x][y] = previousCell; // Restore the previous cell
		previousCell = currentMap[newX][newY]; // Save the new cell's content
		currentMap[newX][newY] = 'M'; // Place the Minotaur in the new cell
		x = newX;
		y = newY;
	}
}

// Minotaur pathing function
void minotaurPath(vector<vector<char>>& currentMap, int& x, int& y, char& previousCell, bool& isGameActive, int a, int b, bool& toggleMonsterVision) {
	if (!toggleMonsterVision) return;

	// Calculate differences in both directions
	// diffX represents the difference in rows, diffY represents the difference in columns
	int diffX = x - a;
	int diffY = y - b;

	// Check which distance is greater or if they are equal
	if (abs(diffX) > abs(diffY)) {
		// Vertical distance is greater, move vertically
		if (diffX > 0) {
			moveMinotaur(currentMap, x, y, 'U', previousCell, isGameActive);
		}
		else {
			moveMinotaur(currentMap, x, y, 'D', previousCell, isGameActive);
		}
	}
	else if (abs(diffY) > abs(diffX)) {
		// Horizontal distance is greater, move horizontally
		if (diffY > 0) {
			moveMinotaur(currentMap, x, y, 'L', previousCell, isGameActive);
		}
		else {
			moveMinotaur(currentMap, x, y, 'R', previousCell, isGameActive);
		}
	}
	else {
		// Distances are equal, prioritize horizontal movement
		if (diffY != 0) {
			if (diffY > 0) {
				moveMinotaur(currentMap, x, y, 'L', previousCell, isGameActive);
			}
			else {
				moveMinotaur(currentMap, x, y, 'R', previousCell, isGameActive);
			}
		}
		else if (diffX != 0) {
			if (diffX > 0) {
				moveMinotaur(currentMap, x, y, 'U', previousCell, isGameActive);
			}
			else {
				moveMinotaur(currentMap, x, y, 'D', previousCell, isGameActive);
			}
		}
	}
}

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
