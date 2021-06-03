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

bool esPosicionValida(posicion);
bool esMatriz(tablero t);
bool CasillaValida(tablero t);



#endif //AJEDREZLITE_AUXILIARES_H
