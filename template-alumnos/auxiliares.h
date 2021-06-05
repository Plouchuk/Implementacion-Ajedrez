//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

/****************************/
/*Ejercicio1*/

bool esMatriz(tablero t);
bool CasillaValida(tablero t);
bool  sinPeonesNoCoronados(tablero t);
bool cantidadValidadePiezas(tablero t);
bool esTableroValido(tablero t);
bool decimeSiEsPosicionValida(pair < tablero, int > const &po);


#endif //AJEDREZLITE_AUXILIARES_H
