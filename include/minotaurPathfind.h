#pragma once

#include "minotaurMovement.h"

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