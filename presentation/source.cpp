#include <iostream>
#include <vector>

using namespace std;

// Revela les cel·les que envolten la posició donada del jugador (Teseu) (fila, columna) en el currentMap
void revealSurroundingArea(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, int row, int col) {
    int n = currentMap.size();
    int m = currentMap[0].size();

    // Itera sobre una àrea de 3x3 centrada al voltant de (fila, columna)
    for (int i = max(0, row - 1); i <= min(row + 1, n - 1); ++i) {
        for (int j = max(0, col - 1); j <= min(col + 1, m - 1); ++j) {
            visibilityMap[i][j] = true; // Estableix la visibilitat d'aquesta cel·la a true
        }
    }
}

// Actualitza el displayedMap basat en el currentMap i visibilityMap
// Només les cel·les que són visibles en el visibilityMap s'actualitzen en el displayedMap
void updateDisplayedMap(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, vector<vector<char>>& displayedMap) {
    int n = currentMap.size();
    int m = currentMap[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Comprova si la cel·la actual és visible
            if (visibilityMap[i][j]) {
                // Actualitza el displayedMap: converteix '_' en currentMap a ' ' en displayedMap
                if (currentMap[i][j] == '_') {
                    displayedMap[i][j] = ' ';
                }
                else {
                    displayedMap[i][j] = currentMap[i][j]; // Manté el caràcter original
                }
            }
        }
    }
}

// Funció principal per actualitzar la matriu de visibilitat
// Itera sobre el currentMap per trobar la posició del jugador i actualitza la visibilitat i el mapa mostrat en conseqüència
void updateVisibilityMatrix(vector<vector<char>>& currentMap, vector<vector<bool>>& visibilityMap, vector<vector<char>>& displayedMap) {
    int n = currentMap.size();
    int m = currentMap[0].size();

    // Itera sobre tot el currentMap per trobar la posició del jugador
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Quan es troba la posició del jugador, revela l'àrea envoltant
            if (currentMap[i][j] == 'T') {
                revealSurroundingArea(currentMap, visibilityMap, i, j);
            }
        }
    }

    // Actualitza el mapa mostrat
    updateDisplayedMap(currentMap, visibilityMap, displayedMap);
}

// Funció de moviment del jugador
void moveTeseu(vector<vector<char>>& currentMap, int& a, int& b, char direction, bool& isGameActive, int& movs) {
    int n = currentMap.size();
    int m = currentMap[0].size();
    int newA = a, newB = b;

    // Determina la nova posició basada en la direcció
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

    // Comprova la nova posició i actua en acord
    if (currentMap[newA][newB] == 'S') {
        cout << "Felicitats has arribat a la sortida!!" << endl;
        cout << "Has fet " << movs << " moviments" << endl;
        isGameActive = false;
    }
    else if (currentMap[newA][newB] == 'M') {
        cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
        cout << "Has fet " << movs << " moviments" << endl;
        isGameActive = false;
    }
    else if (currentMap[newA][newB] == '_') {
        currentMap[a][b] = '_'; // Neteja la posició antiga
        a = newA;
        b = newB;
        currentMap[a][b] = 'T'; // Estableix la nova posició
    }
}

// Funció de moviment del Minotaure
void moveMinotaur(vector<vector<char>>& currentMap, int& x, int& y, char direction, char& previousCell, bool& isGameActive, int& movs) {
    int n = currentMap.size();
    int m = currentMap[0].size();
    int newX = x, newY = y;

    // Determina la nova posició basada en la direcció
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

    // Comprova el contingut de la nova posició i actua en conseqüència
    if (currentMap[newX][newY] == 'T') {
        cout << "Has perdut! El Minotaure t'ha atrapat!" << endl;
        cout << "Has fet " << movs << " moviments." << endl;
        isGameActive = false;
    }
    else {
        // Actualitza la posició del Minotaure
        currentMap[x][y] = previousCell; // Restaura la cel·la anterior
        previousCell = currentMap[newX][newY]; // Desa el contingut de la nova cel·la
        currentMap[newX][newY] = 'M'; // Col·loca el Minotaure en la nova cel·la
        x = newX;
        y = newY;
    }
}

// Funció de camí Minotaure
void minotaurPath(vector<vector<char>>& currentMap, int& x, int& y, char& previousCell, bool& isGameActive, int a, int b, bool& toggleMonsterVision, int& movs) {
    if (!toggleMonsterVision) return;
    // Calcula les diferències en ambdues direccions
    // diffX representa la diferència en files, diffY representa la diferència en columnes
    int diffX = x - a;
    int diffY = y - b;
    // Comprova quina distància és major o si són iguals
    if (abs(diffX) > abs(diffY)) {
        // La distància vertical és major, mou verticalment
        if (diffX > 0) {
            moveMinotaur(currentMap, x, y, 'U', previousCell, isGameActive, movs);
        }
        else {
            moveMinotaur(currentMap, x, y, 'D', previousCell, isGameActive, movs);
        }
    }
    else if (abs(diffY) > abs(diffX)) {
        // La distància horitzontal és major, mou horitzontalment
        if (diffY > 0) {
            moveMinotaur(currentMap, x, y, 'L', previousCell, isGameActive, movs);
        }
        else {
            moveMinotaur(currentMap, x, y, 'R', previousCell, isGameActive, movs);
        }
    }
    else {
        // Si les distàncies són iguals, prioritza el moviment horitzontal
        if (diffY != 0) {
            if (diffY > 0) {
                moveMinotaur(currentMap, x, y, 'L', previousCell, isGameActive, movs);
            }
            else {
                moveMinotaur(currentMap, x, y, 'R', previousCell, isGameActive, movs);
            }
        }
        else if (diffX != 0) {
            if (diffX > 0) {
                moveMinotaur(currentMap, x, y, 'U', previousCell, isGameActive, movs);
            }
            else {
                moveMinotaur(currentMap, x, y, 'D', previousCell, isGameActive, movs);
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
            if (currentMap[i][j] == 'T') {  // Asigna la posicio de Teseu en les variables a i b
                a = i;
                b = j;
                visibilityMap[i][j] = true; // Asigna la cel·la inicial del jugador com a visible
            }
            if (currentMap[i][j] == 'M') {  // Asigna la posicio del minotaure en les variables x i y
                x = i;
                y = j;
            }
            if (currentMap[i][j] == 'S') {
                visibilityMap[i][j] = true; // Asigna la cel·la de la sortida com a visible
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

    while (cin >> c && isGameActive) {  // Bucle principal que detecta el final del joc
        if (toggleMonsterVision == false && visibilityMap[x][y] == true) {  // Inicia el moviment del minotaure quan és revelat pel jugador
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
            moveTeseu(currentMap, a, b, c, isGameActive, movs);
            if (movs % 2 == 1 && isGameActive) {    // Comprova si toca moure el minotaure
                minotaurPath(currentMap, x, y, previousCell, isGameActive, a, b, toggleMonsterVision, movs);
            }
        }
        updateVisibilityMatrix(currentMap, visibilityMap, displayedMap);
    }
    return 0;
}
