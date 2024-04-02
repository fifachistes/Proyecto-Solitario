
#ifndef tablero_h
#define tablero_h

#include <fstream>;
using namespace std;

const int FILS = 6;
const int COLS = 6;
enum tCelda { NULA, VACIA, FICHA };
typedef tCelda tCeldaArray[FILS][COLS];

typedef struct {
	tCelda tCeldaArray[FILS][COLS];
	int fila;
	int columna;
	int fMeta;
	int cMeta;
}tTablero;





void cargar(tTablero& table, ifstream& archivo);
bool valida(const tTablero& table, int fila, int col);
bool eleccionValida(const tTablero& table, int fila, int
	col);
void ponCelda(const tTablero& table, int fila, int col,
	tCelda celda);
bool esFicha(const tTablero& table, int fila, int col);
bool esVacia(const tTablero& table, int fila, int col);
void mostrar(const tTablero& table);
int numFilas(const tTablero& tablero);
int numColumnas(const tTablero& tablero);
void ponMeta(tTablero& tablero, int fila, int col);

void fichaAleatoria(const tTablero& tablero, int& fila, int& columna);
void reseteaTablero(tTablero& tablero, int f, int c);
#endif

