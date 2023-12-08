#pragma once
#include <iostream>
#include <vector>

using namespace std;

void mapa(vector<vector<char>>& mat1, vector<vector<bool>>& mat2, vector<vector<char>>& mat3) {
	int n = mat1.size();
	int m = mat1[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] == 'T') {
				for (int a = i - 1; a <= i + 1; ++a) {
					for (int b = j - 1; b <= j + 1; ++b) {
						if (a >= 0 && a < n && b >= 0 && b < m) {
							mat2[a][b] = true;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat2[i][j]) {
				mat3[i][j] = mat1[i][j];
				if (mat1[i][j] == '_') {
					mat3[i][j] = ' ';
				}
			}
		}
	}
}

