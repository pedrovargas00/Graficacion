#include "MatrizRotacion.h"
#include <stdio.h>
#include <math.h>

MatrizRotacion::MatrizRotacion(){
    //ctor
}

MatrizRotacion::~MatrizRotacion(){
    //dtor
}

void MatrizRotacion::setMatrizX(float grados){

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

void MatrizRotacion::setMatrizY(float grados){

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

void MatrizRotacion::setMatrizZ(float grados){

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

void MatrizRotacion::setTraslacion(float x, float y, float z){

    traslacion[0][0] = 1;
    traslacion[0][1] = 0;
    traslacion[0][2] = 0;
    traslacion[0][3] = x;
    traslacion[1][0] = 0;
    traslacion[1][1] = 1;
    traslacion[1][2] = 0;
    traslacion[1][3] = y;
    traslacion[2][0] = 0;
    traslacion[2][1] = 0;
    traslacion[2][2] = 1;
    traslacion[2][3] = z;
    traslacion[3][0] = 0;
    traslacion[3][1] = 0;
    traslacion[3][2] = 0;
    traslacion[3][3] = 1;
}

void MatrizRotacion::setEscalamiento(float e){

    escalamiento[0][0] = e;
    escalamiento[0][1] = 0;
    escalamiento[0][2] = 0;
    escalamiento[0][3] = 0;
    escalamiento[1][0] = 0;
    escalamiento[1][1] = e;
    escalamiento[1][2] = 0;
    escalamiento[1][3] = 0;
    escalamiento[2][0] = 0;
    escalamiento[2][1] = 0;
    escalamiento[2][2] = e;
    escalamiento[2][3] = 0;
    escalamiento[3][0] = 0;
    escalamiento[3][1] = 0;
    escalamiento[3][2] = 0;
    escalamiento[3][3] = 1;
}

void MatrizRotacion::operarX(float* puntos){

    float aux;
    int i, j, n;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += traslacion[i][n] * x[n][j];
                mAux[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += mAux[i][n] * escalamiento[n][j];
                resultado[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        aux = 0;
        for(j = 0; j < 4; j++){
            aux += resultado[i][j] * puntos[j];
            puntosR[i] = aux;
        }
    }
    return;
}

void MatrizRotacion::operarY(float* puntos){

    float aux;
    int i, j, n;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += traslacion[i][n] * y[n][j];
                mAux[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += mAux[i][n] * escalamiento[n][j];
                resultado[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        aux = 0;
        for(j = 0; j < 4; j++){
            aux += resultado[i][j] * puntos[j];
            puntosR[i] = aux;
        }
    }

    return;
}

void MatrizRotacion::operarZ(float* puntos){

    float aux;
    int i, j, n;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += traslacion[i][n] * z[n][j];
                mAux[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += mAux[i][n] * escalamiento[n][j];
                resultado[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        aux = 0;
        for(j = 0; j < 4; j++){
            aux += resultado[i][j] * puntos[j];
            puntosR[i] = aux;
        }
    }

    return;
}

float MatrizRotacion::getPunto(int i){
    return puntosR[i];
}
