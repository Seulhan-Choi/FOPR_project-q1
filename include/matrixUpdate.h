#pragma once
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