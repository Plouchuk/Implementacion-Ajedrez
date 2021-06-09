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


bool esMatriz(tablero t){
    bool res = true;
    for (int i=0; i < t.size(); i++){
        res = res && t[i].size() == ANCHO_TABLERO;
    }
    res = res && (t.size() == ANCHO_TABLERO);
    return res;
    }

bool CasillaValida(tablero t){
    bool res =true;
    for (int i = 0; i <t.size() ; i++) {
        for (int j = 0; j < t.size() ; j++) {
            res = res && ((t[i][j] == cVACIA) || (PEON <= (t[i][j]).first && REY >= (t[i][j]).first  && ( BLANCO ==  (t[i][j]).second  || NEGRO == (t[i][j]).second )));
        }
    }
    return res;
}

bool  sinPeonesNoCoronados(tablero t){
    bool res = true;
    for (int i = 0; i < t.size() ; i++) {
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
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (t[i][j] == cPEON_N ){
                CPN++;
            }
            else if(t[i][j] == cPEON_B){
                CPB++;
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
    if (CPN <= 8 && CPB <= 8 && CTB <=2 && CTN <= 2 && CAB <= 2 && CAN <= 2 && CRB == 1 && CRN == 1){
        res = true;
    }
    return res;
}

bool esTableroValido(tablero t){
    bool res = false;
    if (t.size() == ANCHO_TABLERO) {
        res = (cantidadValidadePiezas(t) && sinPeonesNoCoronados(t) && CasillaValida(t) && esMatriz(t));
    }
    return res;
}

bool EsPosicionValida(pair < tablero, int > const &po) {
    bool res;
    res =  (po.second == BLANCO || po.second== NEGRO) && esTableroValido(po.first);
    return res;
}


/* EJERCICIO 2*/

bool esPosicionInicial(posicion const &p){
    bool res = true;
    for (int i = 0; i < p.first.size(); ++i) {
        res = res && (p.first[1][i] == cPEON_N) && (p.first[6][i] == cPEON_B) ;
    }
    tablero t = p.first;
    bool fila_0 = t[0][0] == cTORRE_N && t[0][7] == cTORRE_N && t[0][2] == cALFIL_N && t[0][5] == cALFIL_N && t[0][4] == cREY_N;
    bool fila_7 = t[7][0] == cTORRE_B && t[7][7] == cTORRE_B && t[7][2] == cALFIL_B && t[7][5] == cALFIL_B && t[7][4] == cREY_B;
    res = res && fila_0 && fila_7;

    return res;
}

/* Ejercicio 3*/

vector <coordenada > AtacadasPeonB (int i, int k, vector<coordenada> &Ac) {
    coordenada c1 = setCoord(i - 1, k + 1);
    coordenada c2 = setCoord(i - 1, k - 1);
    vector<coordenada> v = {c1, c2};
    for (int j = 0; j < v.size(); ++j) {
        if (coordValida(v[j]) && !pertenece(v[j], Ac)) {
            Ac.push_back(v[j]);
        }

    }
    return Ac;
}

vector <coordenada > AtacadasPeonN (int i, int k, vector<coordenada> &Ac) {
    coordenada c1 = setCoord(i + 1, k + 1);
    coordenada c2 = setCoord(i + 1, k - 1);
    vector<coordenada> v = {c1, c2};
    for (int j = 0; j < v.size(); ++j) {
        if (coordValida(v[j]) && !pertenece(v[j], Ac)) {
            Ac.push_back(v[j]);
        }
    }
    return Ac;
}


bool coordValida (coordenada c){
    bool res;
    res = (c.first >= 0 && c.first <= ANCHO_TABLERO  && c.second >= 0 && c.second <=ANCHO_TABLERO);
    return res;
}
bool pertenece (coordenada o, vector<coordenada> Ac){
    bool res = false;
    for (int i = 0; i < Ac.size(); ++i) {
        if (o == Ac[i]) {
            res = true;
        }
    }
    return res;
}


vector <coordenada > AtacadasRey (int i, int k, vector<coordenada> &Ac) {
    coordenada c1 = setCoord(i + 1, k + 1);
    coordenada c2 = setCoord(i + 1, k - 1);
    coordenada c3 = setCoord(i - 1, k + 1);
    coordenada c4 = setCoord(i - 1, k - 1);
    coordenada c5 = setCoord(i, k + 1);
    coordenada c6 = setCoord(i, k - 1);
    coordenada c7 = setCoord(i + 1, k);
    coordenada c8 = setCoord(i - 1, k);
    vector<coordenada> v = {c1, c2, c3, c4, c5, c6, c7, c8};
    for (int j = 0; j < v.size(); ++j) {
        if (coordValida(v[j]) && !pertenece(v[j], Ac)) {
            Ac.push_back(v[j]);
        }
    }
    return Ac;
}

bool estaOcupada (casilla c) {
    bool res;
    res = (c != cVACIA);
    return res;

}
vector <coordenada > AtacadasAlfil (int i, int k, vector<coordenada> &Ac, tablero t){
    bool cortar1 = false;
    bool cortar2 = false;
    bool cortar3 = false;
    bool cortar4 = false;
    for (int j = 1; j < ANCHO_TABLERO && (!cortar1 || !cortar2 || !cortar3 || !cortar4); j++) {
        /* ESTE VA PARA ABAJO A LA DERECHA */
        if(!cortar1 && coordValida(setCoord(i+j, k+j))){
            if (!estaOcupada(t[i +j][k+j])){
                if(!pertenece(setCoord(i+j, k+j), Ac)) {
                    Ac.push_back(setCoord(i+j, k+j));
                }
            }
            else {

               if (!pertenece(setCoord(i+j, k+j) ,Ac )){
                   Ac.push_back(setCoord(i+j, k+j));

               }
                cortar1 = true;
            }
        }
        /* ESTE VA PARA ARRIBA A LA DERECHA */
        if(!cortar2 && coordValida(setCoord(i-j, k+j))){
            if (!estaOcupada(t[i -j][k+j])){
                if(!pertenece(setCoord(i-j, k+j), Ac)) {
                    Ac.push_back(setCoord(i-j, k+j));
                }
            }
            else {

                if (!pertenece(setCoord(i-j, k+j) ,Ac )){
                    Ac.push_back(setCoord(i-j, k+j));

                }
                cortar2 = true;
            }
        }

        /* ESTE VA PARA ABAJO A LA IZQUIERDA */
        if(!cortar3 && coordValida(setCoord(i+j, k-j))){
            if (!estaOcupada(t[i +j][k-j])){
                if(!pertenece(setCoord(i+j, k-j), Ac)) {
                    Ac.push_back(setCoord(i+j, k-j));
                }
            }
            else {

                if (!pertenece(setCoord(i+j, k-j) ,Ac )){
                    Ac.push_back(setCoord(i+j, k-j));

                }
                cortar3 = true;
            }
        }
        /* ESTE VA PARA ARRIBA LA IZQUIERDA */
        if(!cortar4 && coordValida(setCoord(i-j, k-j))){
            if (!estaOcupada(t[i -j][k-j])){
                if(!pertenece(setCoord(i-j, k-j), Ac)) {
                    Ac.push_back(setCoord(i-j, k-j));
                }
            }
            else {

                if (!pertenece(setCoord(i-j, k-j) ,Ac )){
                    Ac.push_back(setCoord(i-j, k-j));

                }
                cortar4 = true;
            }
        }
    }
    return  Ac;

}

vector <coordenada > AtacadasTorre (int i, int k, vector<coordenada> &Ac, tablero t) {
    bool cortar1 = false;
    bool cortar2 = false;
    bool cortar3 = false;
    bool cortar4 = false;
    for (int j = 1; j < ANCHO_TABLERO && (!cortar1 || !cortar2 || !cortar3 || !cortar4); j++) {
        /* ESTE VA PARA ABAJO */
        if (!cortar1 && coordValida(setCoord(i + j, k ))) {
            if (!estaOcupada(t[i + j][k ])) {
                if (!pertenece(setCoord(i + j, k ), Ac)) {
                    Ac.push_back(setCoord(i + j, k ));
                }
            } else {

                if (!pertenece(setCoord(i + j, k ), Ac)) {
                    Ac.push_back(setCoord(i + j, k ));

                }
                cortar1 = true;
            }
        }
        /* ESTE VA PARA ARRIBA  */
        if (!cortar2 && coordValida(setCoord(i - j, k ))) {
            if (!estaOcupada(t[i - j][k] )) {
                if (!pertenece(setCoord(i - j, k ), Ac)) {
                    Ac.push_back(setCoord(i - j, k ));
                }
            } else {
                if (!pertenece(setCoord(i - j, k ), Ac)) {
                    Ac.push_back(setCoord(i - j, k ));
                }
                cortar2 = true;
            }
        }

        /* ESTE VA PARA LA IZQUIERDA */
        if (!cortar3 && coordValida(setCoord(i , k - j))) {
            if (!estaOcupada(t[i ][k - j])) {
                if (!pertenece(setCoord(i , k - j), Ac)) {
                    Ac.push_back(setCoord(i , k - j));
                }
            } else {

                if (!pertenece(setCoord(i , k - j), Ac)) {
                    Ac.push_back(setCoord(i , k - j));
                }
                cortar3 = true;
            }

        }
        /* ESTE VA PARA DERECHA */
        if (!cortar4 && coordValida(setCoord(i , k + j))) {
            if (!estaOcupada(t[i ][k + j])) {
                if (!pertenece(setCoord(i , k + j), Ac)) {
                    Ac.push_back(setCoord(i , k + j));
                }
            } else {

                if (!pertenece(setCoord(i , k + j), Ac)) {
                    Ac.push_back(setCoord(i , k + j));

                }
                cortar4 = true;
            }


        }
    }
    return Ac;
}

//Prueba modificacion SEBA