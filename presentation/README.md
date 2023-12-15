# Practica de Fonaments de Programació (FOPR)

En aquest joc el jugador esta atrapat en un laberint i ha de trobar la sortida abans que el Minotaure l’agafi. El laberint es representara en 2D usant una quadrícula, i el jugador podrà moure’s per aquesta quadrícula per trobar la sortida.

---

# Documentació

## Funcions Principals

### `moveTeseu`
- **Descripció**: Mou el jugador (Teseu) en una direcció especificada.
- **Funcionament**:
  - Determina la nova posició basada en la direcció ('U', 'D', 'L', 'R').
  - Comprova els límits del mapa per evitar que el jugador surti dels límits.
  - Actualitza l'estat del joc en trobar la sortida ('S') o el Minotaure ('M').

### `moveMinotaur`
- **Descripció**: Mou el Minotaure en una direcció especificada.
- **Funcionament**:
  - Similar a `moveTeseu`, però per al Minotaure.
  - Comprova si el Minotaure atrapa el jugador i actualitza l'estat del joc.

### `monsterpath`
- **Descripció**: Determina la direcció de moviment del Minotaure cap al jugador.
- **Funcionament**:
  - Calcula la diferència de posició entre el Minotaure i el jugador.
  - Prioritza el moviment més llarg o el moviment horitzontal quan les distàncies són iguals.

### `updateVisibilityMatrix` i `revealSurroundingArea`
- **Descripció**: Actualitza la matriu de visibilitat al voltant de la posició del jugador.
- **Funcionament**:
  - `revealSurroundingArea`: Revela les cel·les al voltant de la posició actual del jugador.
  - `updateDisplayedMap`: Converteix els caràcters '_' en espais en blanc a la matriu mostrada.

## Estructura del Joc

### Bucle Principal
- **Descripció**: Controla l'entrada d'usuari i l'estat del joc.
- **Funcionament**:
  - Processa comandes d'usuari per a moviments i accions.
  - Actualitza l'àrea visible i la matriu mostrada després de cada moviment.
  - Finalitza el joc si el jugador arriba a la sortida o és atrapat pel Minotaure.

### Gestió de l'Estat del Joc
- **Variables Clau**:
  - `isGameActive`: Controla si el joc continua o finalitza.
  - `toggleMonsterVision`: Determina si el Minotaure comença a moure's.
  - `previousCell`: Manté el contingut de la cel·la anterior on es trobava el Minotaure.

### Consideracions Addicionals
- **Comentaris**: El codi inclou comentaris detallats per facilitar la comprensió.
- **Testeig**: Es recomana testejar manualment el joc per assegurar-se que tot funciona com s'espera.

## Conclusió

Aquest document proporciona una visió general de com funciona el joc. El codi està ben estructurat i dissenyat per ser modular i fàcil d'entendre. Els comentaris i la documentació ajudaran altres desenvolupadors o usuaris a comprendre el funcionament del joc.


## Llicencia

[MIT](https://choosealicense.com/licenses/mit/)