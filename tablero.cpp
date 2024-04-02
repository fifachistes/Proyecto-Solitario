
#include "tablero.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

const string FG_BLACK = "\x1B[30m";
const string FG_BLUE = "\x1b[34m";
const string BG_BLACK = "\x1B[40m";
const string BG_BROWN = "\x1B[48;5;94m";
const string BG_ORANGE = "\x1B[48;2;204;102;0m";
const string Reset = "\x1b[0m";

const char Horizontal = char(196);
const char UpperLeft = char(218);
const char UpperCross = char(194);
const char UpperRight = char(191);
const char Vertical = char(179);
const char MidLeft = char(195);
const char MidCross = char(197);
const char MidRight = char(180);
const char LowerLeft = char(192);
const char LowerCross = char(193);
const char LowerRight = char(217);
const char Square = char(219);


const int f_meta = 2, c_meta = 1;
const int DEFAULT_COLOR = -1;
// funciones para pintar el tablero
void pintaCabecera() {
    {
        cout << setw(2) << "    ";
        cout << setw(5) << 1;
        for (int i = 2; i <= COLS; i++)
            cout << setw(7) << i;
        cout << endl;
    }
}
void pintaBordeHorizontal(char left, char cross, char right) {
    cout << "    ";
    cout << left;
    for (int i = 0; i < COLS - 1; i++) {
        cout << string(6, Horizontal) << cross;
    }
    cout << string(6, Horizontal) << right << endl;
}

void pintaBordeCelda(int fila, int filaMeta, int colMeta, const tCeldaArray m) {
    cout << "    ";
    for (int k = 0; k < COLS; k++) {
        cout << Vertical;
        if (filaMeta == fila && colMeta == k)
            cout << BG_ORANGE;
        else if (m[fila][k] == 0)
            cout << BG_BLACK;
        else
            cout << BG_BROWN;
        cout << "      ";
        cout << Reset;
    }
    cout << Vertical << endl;
}

void pintaCentroCelda(int fila, int filaMeta, int colMeta, const tCeldaArray m) {
    cout << "  " << setw(2) << fila + 1;
    for (int k = 0; k < COLS; k++) { // cada col
        cout << Vertical;
        if (m[fila][k] == 0) {
            cout << BG_BLACK;
            cout << "      ";
        }
        else {
            if (filaMeta == fila && colMeta == k)
                cout << BG_ORANGE;
            else
                cout << BG_BROWN;
            cout << "  ";
            if (m[fila][k] == 1)
                cout << FG_BLACK;
            else
                cout << FG_BLUE;
            cout << Square << Square;
            cout << Reset;
            if (filaMeta == fila && colMeta == k)
                cout << BG_ORANGE;
            else
                cout << BG_BROWN;
            cout << "  ";
        }
        cout << Reset;
    }
    cout << Vertical << endl;
}

// funciones que hacen update del tablero
void cargar(tTablero& table, ifstream& archivo) {
    int aux;
    if (archivo.is_open()) {
        archivo >> table.fila;
        archivo >> table.columna;

        for (int i = 0; i < table.fila; i++) {
            for (int j = 0; j < table.columna; j++) {
                archivo >> aux;
                if (aux == 0) {
                    table.tCeldaArray[i][j] = NULA;
                }
                else if (aux == 1) {
                    table.tCeldaArray[i][j] = VACIA;
                }
                else if (aux == 2) {
                    table.tCeldaArray[i][j] = FICHA;
                }
            }
        }
      //  archivo >> table.cMeta;
       // archivo >> table.fMeta;
      
        archivo.close(); 
    }
    else {
        cout << "no se pudo abrir ";
    }
}
bool valida(const tTablero& table, int fila, int col) {// lo interpreto como q el numro y fila no son enormes rollo no vale 79 90
    bool valida;
    if (fila <= table.fila && col <= table.columna && table.tCeldaArray[fila][col] != NULA) {
        valida = true;
    }
    else {
        valida = false;

    }
    return valida;
}

bool eleccionValida(const tTablero& table, int fila, int col) {
    bool valido=false;

    if (valida(table, fila, col)) {
        if (table.tCeldaArray[fila][col] == FICHA) {
            valido = true;
        }
       
    }
    return valido;
}
void ponCelda( tTablero& table, int fila, int col, tCelda celda){// referencia cte no se puede modificar
    table.tCeldaArray[fila][col] = celda;
}

bool esFicha(const tTablero& table, int fila, int col)
{
    bool valido = false;

    if (table.tCeldaArray[fila][col] == FICHA) {
        valido = true;
    }

    return valido;
};

bool esVacia(const tTablero& table, int fila, int col)
{
    bool valido = false;

    if (table.tCeldaArray[fila][col] == VACIA) {
        valido == true;
    }

    return valido;
};

void mostrar(const tTablero& table) {
    system("cls"); // borrar consola
    cout << Reset;
    pintaCabecera();
    pintaBordeHorizontal(UpperLeft, UpperCross, UpperRight);
    for (int fila = 0; fila < FILS; fila++) {
        pintaBordeCelda(fila, f_meta, c_meta, table.tCeldaArray);
        pintaCentroCelda(fila, f_meta, c_meta, table.tCeldaArray);
        pintaBordeCelda(fila, f_meta, c_meta, table.tCeldaArray);
        if (fila < FILS - 1) {
            pintaBordeHorizontal(MidLeft, MidCross, MidRight);
        }
        else {
            pintaBordeHorizontal(LowerLeft, LowerCross, LowerRight);
        }
    }
}
int numFilas(const tTablero& tablero) {// es demasiado facil quiza lo he entendido mal uWu
    return tablero.fila;
}
int numColumnas(const tTablero& tablero) {
    return tablero.columna;
}

void ponMeta(tTablero& tablero, int fila, int col) {
    tablero.fMeta = fila;
    tablero.cMeta = col;
}
void dameMeta(const tTablero& tablero, int& fila, int& col) {
    fila = tablero.fMeta;
    col = tablero.cMeta;
}

void fichaAleatoria(const tTablero& tablero, int& fila, int& columna) {
    srand(time(NULL));
    fila = (0 + rand() % (tablero.fila + 1 - 0));
    columna = (0 + rand() % (tablero.columna + 1 - 0));
}
void reseteaTablero(tTablero& tablero, int f, int c) {
    tablero.fila = f;
    tablero.columna = c;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            tablero.tCeldaArray[i][j] = NULA;
        }
    }
}






