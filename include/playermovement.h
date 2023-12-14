#pragma once
#include <iostream>
#include <vector>

using namespace std;

void moveT_D(vector<vector<char>>& mat1, int& a, int& b, bool& trobat, int& movs) {
    //playermove DOWN
    int n = mat1.size();
    if (a + 1 < n) {
        if (mat1[a + 1][b] == 'S') {
            cout << "Felicitats has arribat a la sortida!!" << endl;
            cout << "Has fet " << movs << " moviments." << endl;
            trobat = false;
        }
        else if (mat1[a + 1][b] == 'M') {
            cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
            trobat = false;
        }
        else if (mat1[a + 1][b] == '_') {
            mat1[a + 1][b] = mat1[a][b];
            mat1[a][b] = '_';
            a = a + 1;
        }
    }
}

void moveT_U(vector<vector<char>>& mat1, int& a, int& b, bool& trobat, int& movs) {
    //playermove UP
    if (a - 1 >= 0) {
        if (mat1[a - 1][b] == 'S') {
            cout << "Felicitats has arribat a la sortida!!" << endl;
            cout << "Has fet " << movs << " moviments." << endl;
            trobat = false;
        }
        else if (mat1[a - 1][b] == 'M') {
            cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
            trobat = false;
        }
        else if (mat1[a - 1][b] == '_') {
            mat1[a - 1][b] = mat1[a][b];
            mat1[a][b] = '_';
            a = a - 1;
        }
    }
}

void moveT_L(vector<vector<char>>& mat1, int& a, int& b, bool& trobat, int& movs) {
    //playermove LEFT
    if (b - 1 >= 0) {
        if (mat1[a][b - 1] == 'S') {
            cout << "Felicitats has arribat a la sortida!!" << endl;
            cout << "Has fet " << movs << " moviments." << endl;
            trobat = false;
        }
        else if (mat1[a][b - 1] == 'M') {
            cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
            trobat = false;
        }
        else if (mat1[a][b - 1] == '_') {
            mat1[a][b - 1] = mat1[a][b];
            mat1[a][b] = '_';
            b = b - 1;
        }
    }
}

void moveT_R(vector<vector<char>>& mat1, int& a, int& b, bool& trobat, int& movs) {
    //playermove RIGHT
    int m = mat1[0].size();
    if (b + 1 < m) {
        if (mat1[a][b + 1] == 'S') {
            cout << "Felicitats has arribat a la sortida!!" << endl;
            cout << "Has fet " << movs << " moviments." << endl;
            trobat = false;
        }
        else if (mat1[a][b + 1] == 'M') {
            cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
            trobat = false;
        }
        else if (mat1[a][b + 1] == '_') {
            mat1[a][b + 1] = mat1[a][b];
            mat1[a][b] = '_';
            b = b + 1;
        }
    }
}