#include "juego.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

bool cargar(tJuego& juego, string nombre) {
	ifstream archivo;
	archivo.open(nombre+".txt");

	tTablero tablero;
	cargar(tablero, archivo);
	juego.estado = JUGANDO;
	juego.tablero = tablero;
}
void mostrar(const tJuego& juego) {
	mostrar(juego.tablero);
}
void ejecutarMovimiento(tJuego& juego) {
	int col;
	int fila;
	tMovimiento mov = leeMovimiento(juego.tablero, fila, col);
	movimientoFicha(juego.tablero, fila, col, mov);
	actualizaEstado(juego);
}
void actualizaEstado(tJuego& juego) {
	if (ganador(juego)) {
		juego.estado = GANADOR;
	}
	else {
		bool movimientos = hayMovimientos(juego);
		if (movimientos) {
			juego.estado = JUGANDO;
		}
		else {
			juego.estado = BLOQUEO;
		}
	}
}
bool ganador(const tJuego& juego) {
	int numFichas = 0;
	bool valido = false;
	for (int i = 0; i < juego.tablero.fila; i++) {
		for (int j = 0; j < juego.tablero.columna; j++) {
			if (juego.tablero.tCeldaArray[i][j] == FICHA) {
				numFichas += 1;
			}
		}
	}

	if (numFichas == 1 && juego.tablero.tCeldaArray[juego.tablero.fMeta][juego.tablero.cMeta] == FICHA) {
		valido = true;
	}
	return valido;
}
bool hayMovimientos(const tJuego& juego) {
	int fila = 0;
	int columna = 0;
	tMovimientoLista posibles;
	bool movimientos = false;
	while (!movimientos || fila < juego.tablero.fila || columna < juego.tablero.columna) {
		movimientos = movimientosPosibles(juego.tablero, fila, columna, posibles);
		columna += 1;
		if (columna == 6) {
			columna = 0;
			fila += 1;
		}
	}
	return movimientos;
}

void generar(tJuego& juego, int pasos) {

}

bool movimientoInverso(tJuego& juego) {

}
