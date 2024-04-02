#ifndef juego_h
#define juego_h

#include "tablero.h"
#include "movimiento.h"
#include <fstream>;

using namespace std;

typedef enum tEstado {JUGANDO, GANADOR, BLOQUEO};
typedef struct {
	tTablero tablero;
	tEstado estado;
} tJuego;

bool cargar(tJuego& juego, string nombre);
void mostrar(const tJuego& juego);
void ejecutarMovimiento(tJuego& juego);
void actualizaEstado(tJuego& juego);
bool ganador(const tJuego& juego);
bool hayMovimientos(const tJuego& juego);

void generar(tJuego& juego, int pasos);
bool movimientoInverso(tJuego& juego);
#endif
