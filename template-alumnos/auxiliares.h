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
bool EsPosicionValida(pair < tablero, int > const &po);
bool esPosicionInicial(posicion const &p);
vector <coordenada > AtacadasPeonB (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasPeonN (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasRey (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasAlfil (int i, int k, vector<coordenada> &Ac, tablero t);
bool pertenece (coordenada o, vector<coordenada> Ac);
bool coordValida (coordenada c);
bool estaOcupada (coordenada c);
vector <coordenada > AtacadasTorre (int i, int k, vector<coordenada> &Ac, tablero t);

#endif //AJEDREZLITE_AUXILIARES_H
