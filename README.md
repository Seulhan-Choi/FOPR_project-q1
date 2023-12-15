# Practica de Fonaments de Programaci� (FOPR)

En aquest joc el jugador esta atrapat en un laberint i ha de trobar la sortida abans que el Minotaure l�agafi. El laberint es representara en 2D usant una quadr�cula, i el jugador podr� moure�s per aquesta quadr�cula per trobar la sortida.

---

# Documentaci�

## Funcions Principals

### `moveTeseu`
- **Descripci�**: Mou el jugador (Teseu) en una direcci� especificada.
- **Funcionament**:
  - Determina la nova posici� basada en la direcci� ('U', 'D', 'L', 'R').
  - Comprova els l�mits del mapa per evitar que el jugador surti dels l�mits.
  - Actualitza l'estat del joc en trobar la sortida ('S') o el Minotaure ('M').

### `moveMinotaur`
- **Descripci�**: Mou el Minotaure en una direcci� especificada.
- **Funcionament**:
  - Similar a `moveTeseu`, per� per al Minotaure.
  - Comprova si el Minotaure atrapa el jugador i actualitza l'estat del joc.

### `monsterpath`
- **Descripci�**: Determina la direcci� de moviment del Minotaure cap al jugador.
- **Funcionament**:
  - Calcula la difer�ncia de posici� entre el Minotaure i el jugador.
  - Prioritza el moviment m�s llarg o el moviment horitzontal quan les dist�ncies s�n iguals.

### `updateVisibilityMatrix` i `revealSurroundingArea`
- **Descripci�**: Actualitza la matriu de visibilitat al voltant de la posici� del jugador.
- **Funcionament**:
  - `revealSurroundingArea`: Revela les cel�les al voltant de la posici� actual del jugador.
  - `updateDisplayedMap`: Converteix els car�cters '_' en espais en blanc a la matriu mostrada.

## Estructura del Joc

### Bucle Principal
- **Descripci�**: Controla l'entrada d'usuari i l'estat del joc.
- **Funcionament**:
  - Processa comandes d'usuari per a moviments i accions.
  - Actualitza l'�rea visible i la matriu mostrada despr�s de cada moviment.
  - Finalitza el joc si el jugador arriba a la sortida o �s atrapat pel Minotaure.

### Gesti� de l'Estat del Joc
- **Variables Clau**:
  - `isGameActive`: Controla si el joc continua o finalitza.
  - `toggleMonsterVision`: Determina si el Minotaure comen�a a moure's.
  - `previousCell`: Mant� el contingut de la cel�la anterior on es trobava el Minotaure.

### Consideracions Addicionals
- **Comentaris**: El codi inclou comentaris detallats per facilitar la comprensi�.
- **Testeig**: Es recomana testejar manualment el joc per assegurar-se que tot funciona com s'espera.

## Conclusi�

Aquest document proporciona una visi� general de com funciona el joc. El codi est� ben estructurat i dissenyat per ser modular i f�cil d'entendre. Els comentaris i la documentaci� ajudaran altres desenvolupadors o usuaris a comprendre el funcionament del joc.


## Llicencia

[MIT](https://choosealicense.com/licenses/mit/)