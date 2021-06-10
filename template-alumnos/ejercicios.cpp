#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = true;
    // completar codigo
    resp = resp && EsPosicionValida(p);
    return resp;
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    bool resp ;
    // completar codigo
    resp = esPosicionInicial(p) && p.second == BLANCO;
    return resp;
}
// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    vector <coordenada> cA;
    tablero t = p.first;
    for (int i = 0; i < t.size() ; ++i) {
        for (int k = 0; k < t.size()  ; ++k) {
        if(t[i][k] == cPEON_B && j == BLANCO){
          cA = AtacadasPeonB(i,k,cA );
        }
        if(t[i][k] == cPEON_N && j == NEGRO){
               cA= AtacadasPeonN(i,k,cA);
            }
        if ((t[i][k] ).first == REY && (t[i][k] ).second == j ){
               cA =  AtacadasRey (i,k, cA);
            }
        if ((t[i][k] ).first == ALFIL && (t[i][k] ).second == j ){
                cA = AtacadasAlfil(i ,k , cA, t);
            }
            if ((t[i][k] ).first == TORRE && (t[i][k] ).second == j ){
                cA = AtacadasTorre(i ,k , cA, t);
            }
        }

    }
    // completar codigo
    return cA;
}
// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    bool resp ;
    resp = esCapturaoMovValido(p1, o, d) && loDemasIgual(p1, p2, o, d)  && movimientoBienRealizado(p1, p2, o, d);
    // completar codigo
    return resp;
}
// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    // completar codigo
    for (int i = 0; i < (p.first).size(); ++i) {
        (p.first)[i] =  ordenarFila(p.first[i]);
    }

    return;
}
// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    // completar codigo
    return;
}
// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;
    // completar codigo
    return resp;
}
