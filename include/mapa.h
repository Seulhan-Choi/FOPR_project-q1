#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Function 'mapa' updates the visibility matrix(mat2) and applies it onto the visible matrix(mat3)
// mat1: Input matrix of characters.
// mat2: Matrix of booleans to be updated based on conditions in mat1.
// mat3: Output matrix of characters, modified based on mat1 and mat2.
void mapa(vector<vector<char>>& mat1, vector<vector<bool>>& mat2, vector<vector<char>>& mat3) {
    // Determine the number of rows (n) and columns (m) in mat1.
    int n = mat1.size();
    int m = mat1[0].size();

    // Iterate over each element in mat1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check if the current element is 'T'.
            if (mat1[i][j] == 'T') {
                // Iterate over a 3x3 submatrix surrounding the 'T'.
                for (int a = i - 1; a <= i + 1; ++a) {
                    for (int b = j - 1; b <= j + 1; ++b) {
                        // Ensure the indices are within the bounds of the matrix.
                        if (a >= 0 && a < n && b >= 0 && b < m) {
                            // Set the corresponding element in mat2 to true.
                            mat2[a][b] = true;
                        }
                    }
                }
            }
        }
    }

    // Iterate over each element in mat2.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check if the corresponding element in mat2 is true.
            if (mat2[i][j] == true) {
                // Copy the element from mat1 to mat3.
                mat3[i][j] = mat1[i][j];
                // If the element in mat1 is '_', replace it with a space in mat3.
                if (mat1[i][j] == '_') {
                    mat3[i][j] = ' ';
                }
            }
        }
    }
}

