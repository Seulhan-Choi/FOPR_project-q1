#pragma once

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

 