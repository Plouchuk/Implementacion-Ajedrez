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

/*Ejercicio2*/

bool esPosicionInicial(posicion const &p);
/*Ejercicio 3*/

vector <coordenada > AtacadasPeonB (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasPeonN (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasRey (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasAlfil (int i, int k, vector<coordenada> &Ac, tablero t);
bool pertenece (coordenada o, vector<coordenada> Ac);
bool coordValida (coordenada c);
bool estaOcupada (coordenada c);
vector <coordenada > AtacadasTorre (int i, int k, vector<coordenada> &Ac, tablero t);
/*Ejercicio 4*/
bool esCapturaoMovValido(posicion p, coordenada o, coordenada d);
bool movPeonB (coordenada d, coordenada o);
bool movPeonN (coordenada d, coordenada o);
bool loDemasIgual(posicion p1, posicion p2, coordenada o, coordenada d);
bool verSiEstaCoronado(posicion p1, posicion p2, coordenada o, coordenada d);
bool movimientoBienRealizado (posicion p1, posicion p2, coordenada o, coordenada d);
/*Ejercicio 5*/

vector<casilla> ordenarFila(vector<casilla> v );
void ordernarv (vector<casilla> v);
int encontrarMinPosNoVacia(vector<casilla> v, int d, int h);
void swap(vector<casilla> &v, int i, int j);
#endif //AJEDREZLITE_AUXILIARES_H
