#include "Matriz.h"
#include <math.h>
#include <stdio.h>

Matriz::Matriz(){
    //ctor
}

Matriz::~Matriz(){
    //dtor
}

void Matriz::setMatrizX(float grados){

    x[0][0] = 1;
    x[0][1] = 0;
    x[0][2] = 0;
    x[0][3] = 0;
    x[1][0] = 0;
    x[1][1] = cos(grados);
    x[1][2] = -sin(grados);
    x[1][3] = 0;
    x[2][0] = 0;
    x[2][1] = sin(grados);
    x[2][2] = cos(grados);
    x[2][3] = 0;
    x[3][0] = 0;
    x[3][1] = 0;
    x[3][2] = 0;
    x[3][3] = 1;
}

void Matriz::setMatrizY(float grados){

    y[0][0] = cos(grados);
    y[0][1] = 0;
    y[0][2] = sin(grados);
    y[0][3] = 0;
    y[1][0] = 0;
    y[1][1] = 1;
    y[1][2] = 0;
    y[1][3] = 0;
    y[2][0] = -sin(grados);
    y[2][1] = 0;
    y[2][2] = cos(grados);
    y[2][3] = 0;
    y[3][0] = 0;
    y[3][1] = 0;
    y[3][2] = 0;
    y[3][3] = 1;
}

void Matriz::setMatrizZ(float grados){

    z[0][0] = cos(grados);
    z[0][1] = -sin(grados);
    z[0][2] = 0;
    z[0][3] = 0;
    z[1][0] = sin(grados);
    z[1][1] = cos(grados);
    z[1][2] = 0;
    z[1][3] = 0;
    z[2][0] = 0;
    z[2][1] = 0;
    z[2][2] = 1;
    z[2][3] = 0;
    z[3][0] = 0;
    z[3][1] = 0;
    z[3][2] = 0;
    z[3][3] = 1;
}

float* Matriz::operarX(float* puntos){

    float aux;

    for(int i = 0; i < 4; i++){
        aux = 0;
        for(int j = 0; j < 4; j++){
            aux += x[i][j] * puntos[j];
            puntosR[i] = aux;
            //printf("\nPunto %d : %f",i , puntosR[i]);
        }
        //printf("\n");
    }
    return puntosR;
}

float* Matriz::operarY(float* puntos){

    float aux;
    printf("\n---Ingresa----");
    for(int i = 0; i < 4; i++){
        aux = 0;
        for(int j = 0; j < 4; j++){
            printf("\ny*puntos: %f  %f, i: %d", y[i][j], puntos[j], i);
            aux += y[i][j] * puntos[j];
            puntosR[i] = aux;
        }
        //printf("\nPuntoY %d : %f", i, puntosR[i]);
        //printf("\n");
    }
    return puntosR;
}

float* Matriz::operarZ(float* puntos){

    float aux;

    for(int i = 0; i < 4; i++){
        aux = 0;
        for(int j = 0; j < 4; j++){
            aux += z[i][j] * puntos[j];
            puntosR[i] = aux;
            //printf("\nPunto %d : %f", i, puntosR[i]);
        }
        //printf("\n");
    }
    return puntosR;
}
