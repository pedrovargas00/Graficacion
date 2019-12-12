#include "Matriz.h"
#include <stdio.h>
#include <math.h>

Matriz::Matriz(){
    //ctor
}

Matriz::~Matriz(){
    //dtor
}

void Matriz::setPuntos(float x0, float y0, float z0, float x1, float y1, float z1){

    float x = (x1 - x0), y = (y1 - y0), z = (z1 - z0);
    float v = sqrt(pow((double)x, 2) + pow((double)y, 2) + pow((double)z, 2));

    a = x/v;
    b = y/v;
    c = z/v;
    d = sqrt(pow((double)b, 2) + pow((double)c, 2));
}

void Matriz::matrices(float grado){

    float grados = (grado*M_PI)/180;

    rotacionX[0][0] = 1;
    rotacionX[0][1] = 0;
    rotacionX[0][2] = 0;
    rotacionX[0][3] = 0;
    rotacionX[1][0] = 0;
    rotacionX[1][1] = c/d;
    rotacionX[1][2] = -b/d;
    rotacionX[1][3] = 0;
    rotacionX[2][0] = 0;
    rotacionX[2][1] = b/d;
    rotacionX[2][2] = c/d;
    rotacionX[2][3] = 0;
    rotacionX[3][0] = 0;
    rotacionX[3][1] = 0;
    rotacionX[3][2] = 0;
    rotacionX[3][3] = 1;

    //-------------------------

    rotacionXI[0][0] = 1;
    rotacionXI[0][1] = 0;
    rotacionXI[0][2] = 0;
    rotacionXI[0][3] = 0;
    rotacionXI[1][0] = 0;
    rotacionXI[1][1] = (-1) * rotacionX[1][1];
    rotacionXI[1][2] = (-1) * rotacionX[1][2];
    rotacionXI[1][3] = 0;
    rotacionXI[2][0] = 0;
    rotacionXI[2][1] = (-1) * rotacionX[2][1];
    rotacionXI[2][2] = (-1) * rotacionX[2][2];
    rotacionXI[2][3] = 0;
    rotacionXI[3][0] = 0;
    rotacionXI[3][1] = 0;
    rotacionXI[3][2] = 0;
    rotacionXI[3][3] = 1;

    //--------------------------------

    rotacionY[0][0] = d;
    rotacionY[0][1] = 0;
    rotacionY[0][2] = -a;
    rotacionY[0][3] = 0;
    rotacionY[1][0] = 0;
    rotacionY[1][1] = 1;
    rotacionY[1][2] = 0;
    rotacionY[1][3] = 0;
    rotacionY[2][0] = a;
    rotacionY[2][1] = 0;
    rotacionY[2][2] = d;
    rotacionY[2][3] = 0;
    rotacionY[3][0] = 0;
    rotacionY[3][1] = 0;
    rotacionY[3][2] = 0;
    rotacionY[3][3] = 1;

    //----------------------------------

    rotacionYI[0][0] = rotacionY[0][0];
    rotacionYI[0][1] = 0;
    rotacionYI[0][2] = rotacionY[0][2];
    rotacionYI[0][3] = 0;
    rotacionYI[1][0] = 0;
    rotacionYI[1][1] = rotacionY[1][1];
    rotacionYI[1][2] = 0;
    rotacionYI[1][3] = 0;
    rotacionYI[2][0] = rotacionY[2][0];
    rotacionYI[2][1] = 0;
    rotacionYI[2][2] = rotacionY[2][2];
    rotacionYI[2][3] = 0;
    rotacionYI[3][0] = 0;
    rotacionYI[3][1] = 0;
    rotacionYI[3][2] = 0;
    rotacionYI[3][3] = rotacionY[3][3];

    //---------------------------------

    rotacionZ[0][0] = cos(grados);
    rotacionZ[0][1] = -sin(grados);
    rotacionZ[0][2] = 0;
    rotacionZ[0][3] = 0;
    rotacionZ[1][0] = sin(grados);
    rotacionZ[1][1] = cos(grados);
    rotacionZ[1][2] = 0;
    rotacionZ[1][3] = 0;
    rotacionZ[2][0] = 0;
    rotacionZ[2][1] = 0;
    rotacionZ[2][2] = 1;
    rotacionZ[2][3] = 0;
    rotacionZ[3][0] = 0;
    rotacionZ[3][1] = 0;
    rotacionZ[3][2] = 0;
    rotacionZ[3][3] = 1;

}

void Matriz::setTraslacion(float x, float y, float z){

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

void Matriz::setEscalamiento(float e){

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

void Matriz::operarRotacion(){

    int i, j, k;
    float aux;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
                aux = 0;
            for(k = 0; k < 4; k++){
                aux += rotacionXI[i][k] * rotacionYI[k][j];
                mAux2[i][j] = aux;
            }

        }

    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
                aux = 0;
            for(k = 0; k < 4; k++){
                aux += mAux2[i][k] * rotacionZ[k][j];
                mAux[i][j] = aux;
            }
        }

    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
                aux = 0;
            for(k = 0; k < 4; k++){
                aux += mAux[i][k] * rotacionY[k][j];
                mAux2[i][j] = aux;
            }
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
                aux = 0;
            for(k = 0; k < 4; k++){
                aux += mAux2[i][k] * rotacionX[k][j];
                rotacion[i][j] = aux;
            }
        }
    }

    return;
}

void Matriz::operar(float* p){

    int i, j, n;
    float aux;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            aux = 0;
            for(n = 0; n < 4; n++){
                aux += traslacion[i][n] * rotacion[n][j];
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
            aux += resultado[i][j] * p[j];
            puntosR[i] = aux;
        }
    }

    return;
}

float Matriz::getPunto(int i){
    return puntosR[i];
}
