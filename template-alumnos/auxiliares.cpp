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

bool decimeSiEsPosicionValida(pair < tablero, int > const &po) {
    bool res;
 res =   (po.second == BLANCO || po.second== NEGRO) && esTableroValido(po.first);
    return res;
}

bool esMatriz(tablero t){
    bool res = true;
    for (int i=0; i < ANCHO_TABLERO; i++){
        res = res && t[i].size() == ANCHO_TABLERO;
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
        res = res && ( (t[0][i]).first != PEON && (t[ANCHO_TABLERO - 1 ][i]).first != PEON);
    }
    return res;
}

bool cantidadValidadePiezas(tablero t){
    bool res = false;
    int CPN = 0;
    int CPB = 0;
    int CAN = 0;
    int CAB = 0;
    int CTB = 0;
    int CTN = 0;
    int CRN = 0;
    int CRB = 0;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int j = 0; j < ANCHO_TABLERO; ++j) {
            if (t[i][j] == cPEON_N ){
                CPN++;
            }
            else if(t[i][j] == cPEON_B){
                CPB ++;
            }
            else if (t[i][j] == cALFIL_B){
                CAB++;
            }
            else if (t[i][j] == cALFIL_B){
                CAN++;
            }
            else if (t[i][j] == cTORRE_B){
                CTB++;
            }
            else if (t[i][j] == cTORRE_N){
                CTN++;
            }
            else if (t[i][j] == cREY_B){
                CRB++;
            }
            else if (t[i][j] == cREY_N){
                CRN++;
            }

        }

    }
    if (CPN <= 8 && CPB <= 8 && CTB <=2 && CTN <= 2 && CAB <= 2 && CAN <= 2 && CRB == 1 && CRN ==1){
        res = true;
    }
    return res;
}

bool esTableroValido(tablero t){
    bool res = false;
    if(cantidadValidadePiezas(t) == true && sinPeonesNoCoronados(t) == true && CasillaValida(t) == true && esMatriz(t) == true){
        res = true;
    }
    return res;
}