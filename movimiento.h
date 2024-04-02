
#ifndef movimiento_h
#define movimiento_h

#include "tablero.h"
#include <fstream>;

using namespace std;

const int maxMovimientos = 4;

enum tDireccion {ARRIBA, DERECHA, ABAJO, IZQUIERDA};
typedef struct {
	tDireccion direccion;
	int filaSaltada;
	int columnaSaltada;
	int filaDestino;
	int columnaDestino;
} tMovimiento;
typedef tMovimiento tMovimientoArray[maxMovimientos];
typedef struct {
	tMovimiento movimientoArray[maxMovimientos];
	int pos = 0;
} tMovimientoLista;


bool fichaBloqueada(const tTablero& tablero, int fila, int col);
tMovimiento moviendo(tDireccion dir, int fila, int col);
tMovimiento leeMovimiento(const tTablero& tablero, int& fila, int& col);
bool movimientosPosibles(const tTablero& tablero, int fila, int col, tMovimientoLista& listaMov);
tMovimiento eligeMovimiento(const tMovimientoLista& listaMov);
void movimientoFicha(tTablero& tablero, int fila, int col, const tMovimiento& mov);

bool eligeMovimientoInverso(const tTablero& tablero, int fila, int col, tMovimiento& mov);
void realizaMovimientoInverso(tTablero& tablero, int fila, int col, const tMovimiento& mov);
void realizaMovimientoInverso(tTablero& tablero, int fila, int col, const tMovimiento& mov);
#endif
