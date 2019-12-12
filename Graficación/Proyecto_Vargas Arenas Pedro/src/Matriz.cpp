#include "Matriz.h"
#include <math.h>
#include <stdio.h>

Matriz::Matriz(){

}

Matriz::~Matriz(){
    //dtor
}

void Matriz::setRotacion(float r){

    rt[0][0] = cos(r);
    rt[0][1] = -sin(r);
    rt[0][2] = 0;
    rt[1][0] = sin(r);
    rt[1][1] = cos(r);
    rt[1][2] = 0;
    rt[2][0] = 0;
    rt[2][1] = 0;
    rt[2][2] = 1;
}

void Matriz::setTraslacion(float x, float y){

    tl[0][0] = 1;
    tl[0][1] = 0;
    tl[0][2] = x;
    tl[1][0] = 0;
    tl[1][1] = 1;
    tl[1][2] = y;
    tl[2][0] = 0;
    tl[2][1] = 0;
    tl[2][2] = 1;
}

void Matriz::setEscalamiento(float e){

    ec[0][0] = e;
    ec[0][1] = 0;
    ec[0][2] = 0;
    ec[1][0] = 0;
    ec[1][1] = e;
    ec[1][2] = 0;
    ec[2][0] = 0;
    ec[2][1] = 0;
    ec[2][2] = 1;
}

void Matriz::operar(float* p){

    int i, j, n;
    float aux;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            aux = 0;
            for(n = 0; n < 3; n++){
                aux += tl[i][n] * rt[n][j];
                mAux[i][j] = aux;
            }
        }
    }
    //printf("\n------------------------->");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            aux = 0;
            for(n = 0; n < 3; n++){
                aux += mAux[i][n] * ec[n][j];
                resultado[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 3; i++){
        aux = 0;
        for(j = 0; j < 3; j++){
            aux += resultado[i][j] * p[j];
            puntosR[i] = aux;
        }
    }
    return;
}
