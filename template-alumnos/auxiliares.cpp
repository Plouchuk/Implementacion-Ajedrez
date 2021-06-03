#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

/* EJERCICIO 1*/

bool esPosicionValida(posicion const &p){
    /*esJugadorValido(p) && esTableroValido(Tablero(p));*/
    for(int i=0; i< (p.first).size(); i++ ){

    }
}

bool esMatriz(tablero t){
    bool res = true;
    for (int i=0; i < ANCHO_TABLERO; i++){
        res = res && t[i].size() == ANCHO_TABLERO
    }
    res = res && (t.size() == ANCHO_TABLERO);
    return res;
    }

bool CasillaValida(tablero t){
    bool res =true;
    for (int i = 0; i <ANCHO_TABLERO ; i++) {
        for (int j = 0; j < ANCHO_TABLERO ; j++) {
            res = res && ((t[i][j] == cVACIA) || (PEON <= (t[i][j]).first && REY >= (t[i][j]).first  && ( BLANCO ==  (t[i][j]).second  || NEGRO == (t[i][j]).second )));
        }
    }
    return res;
}

bool  sinPeonesNoCoronados(tablero t){
    bool res = true;
    for (int i = 0; i < ANCHO_TABLERO ; ++i) {
        res = res && ( (t[0][i]).first != PEON && (t[ANCHO_TABLERO - 1 ][i]).first == PEON)
    }
    return res;
}
