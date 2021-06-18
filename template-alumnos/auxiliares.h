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

/*Ejercicio3*/
vector <coordenada > AtacadasPeonB (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasPeonN (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasRey (int i, int k, vector<coordenada> &Ac);
vector <coordenada > AtacadasAlfil (int i, int k, vector<coordenada> &Ac, tablero t);
bool pertenece (coordenada o, vector<coordenada> Ac);
bool coordValida (coordenada c);
bool estaOcupada (coordenada c);
vector <coordenada > AtacadasTorre (int i, int k, vector<coordenada> &Ac, tablero t);

/*Ejercicio4*/
bool esCapturaoMovValido(posicion p, coordenada o, coordenada d);
bool movPeonB (coordenada d, coordenada o);
bool movPeonN (coordenada d, coordenada o);
bool loDemasIgual(posicion p1, posicion p2, coordenada o, coordenada d);
bool verSiEstaCoronado(posicion p1, posicion p2, coordenada o, coordenada d);
bool movimientoBienRealizado (posicion p1, posicion p2, coordenada o, coordenada d);

/*Ejercicio5*/
vector<casilla> ordenarFila(vector<casilla> &v);
int findMinPosition(vector<casilla> &v, int d, int h);
void swap(vector<casilla> &v ,int i, int j);
void selectionSort(vector<casilla> &v);
bool esJaque(posicion p);
vector <coordenada> Atacadas ( posicion const &p, int j );
int jugadorContrario (posicion p);
void posicionSig(posicion &p, coordenada o, coordenada d);
bool esMovLegal(posicion p, coordenada o, coordenada d);
bool hayMovLegal (posicion p);
bool soloQuedanReyes (posicion p);
posicion LaSigPosEs(posicion p, coordenada o, coordenada d);

/*Ejercicio 7*/

bool esJaqueEnCoordDistintaA(posicion p, coordenada d);
coordenada dameAlReyJ(posicion p, int j);
vector <coordenada> AtacadasXtodasMenosC ( posicion const &p, int j , coordenada c);
bool jaqueDescubierto (posicion p);

/*Ejercicio 8*/

pair<coordenada, coordenada> unicoMovValido(posicion p);

// EJERCICIO 9
bool estaForzado(posicion p);
bool esJaqueMate(posicion p);
vector <coordenada> AtacadasPorC ( posicion const &p, int c1, int c2 );
bool ganasEn1(posicion p);

posicion CaminoForzado(posicion p);
// 9v2
int enCuantoGano( posicion const &p );
bool conEstaPiezaFuerzo(posicion p, coordenada c);
bool conEstaPiezaFuerzoYGano(posicion p, coordenada c);

#endif //AJEDREZLITE_AUXILIARES_H
