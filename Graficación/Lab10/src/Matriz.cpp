#include "Matriz.h"
#include <math.h>

Matriz::Matriz(){
    //ctor
}

Matriz::~Matriz(){
    //dtor
}

void puntos(){

    float modulo = sqrt(pow(p2[0] - p1[0]) + pow(p2[1] - p1[1]) + pow(p2[2] - p1[2]));

    a = (p2[0] - p1[0])/modulo;
    b = (p2[1] - p1[1])/modulo;
    c = (p2[2] - p1[2])/modulo;
    d = sqrt(pow(b) + pow(c));
}

void setTraslacion(float x, float y, float z){

    traslacion[0][0] = 1;
    traslacion[0][1] = 0;
    traslacion[0][2] = 0;
    traslacion[0][3] = -x;
    traslacion[1][0] = 0;
    traslacion[1][1] = 1;
    traslacion[1][2] = 0;
    traslacion[1][3] = -y;
    traslacion[2][0] = 0;
    traslacion[2][1] = 0;
    traslacion[2][2] = 1;
    traslacion[2][3] = -z;
    traslacion[3][0] = 0;
    traslacion[3][1] = 0;
    traslacion[3][2] = 0;
    traslacion[3][3] = 1;
}

void setTraslacionI(){

    traslacionI[0][0] = (-1) * traslacion[0][0];
    traslacionI[0][1] = 0;
    traslacionI[0][2] = 0;
    traslacionI[0][3] = (-1) * traslacion[0][3];
    traslacionI[1][0] = 0;
    traslacionI[1][1] = (-1) * traslacion[1][1];
    traslacionI[1][2] = 0;
    traslacionI[1][3] = (-1) * traslacion[1][3];
    traslacionI[2][0] = 0;
    traslacionI[2][1] = 0;
    traslacionI[2][2] = (-1) * traslacion[2][2];
    traslacionI[2][3] = (-1) * traslacion[2][3];
    traslacionI[3][0] = 0;
    traslacionI[3][1] = 0;
    traslacionI[3][2] = 0;
    traslacionI[3][3] = (-1) * traslacion[3][3];
}

void setRotacionX(){

    float c = c/d, s = b/d;

    rotacionX[0][0] = 1;
    rotacionX[0][1] = 0;
    rotacionX[0][2] = 0;
    rotacionX[0][3] = 0;
    rotacionX[1][0] = 0;
    rotacionX[1][1] = c;
    rotacionX[1][2] = -s;
    rotacionX[1][3] = 0;
    rotacionX[2][0] = 0;
    rotacionX[2][1] = s;
    rotacionX[2][2] = c;
    rotacionX[2][3] = 0;
    rotacionX[3][0] = 0;
    rotacionX[3][1] = 0;
    rotacionX[3][2] = 0;
    rotacionX[3][3] = 1;

}

void setRotacionXI(){

    rotacionXI[0][0] = (-1) * rotacionX[0][0];
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
    rotacionXI[3][3] = (-1) * rotacionX[3][3];
}

void setRotacionY(){

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
}

void setRotacionYI(){

    rotacionYI[0][0] = (-1) rotacionY[0][0];
    rotacionYI[0][1] = 0;
    rotacionYI[0][2] = (-1) rotacionY[0][2];
    rotacionYI[0][3] = 0;
    rotacionYI[1][0] = 0;
    rotacionYI[1][1] = (-1) rotacionY[1][1];
    rotacionYI[1][2] = 0;
    rotacionYI[1][3] = 0;
    rotacionYI[2][0] = (-1) rotacionY[2][0];
    rotacionYI[2][1] = 0;
    rotacionYI[2][2] = (-1) rotacionY[2][2];
    rotacionYI[2][3] = 0;
    rotacionYI[3][0] = 0;
    rotacionYI[3][1] = 0;
    rotacionYI[3][2] = 0;
    rotacionYI[3][3] = (-1) rotacionY[3][3];
}

void setRotacionZ(float grados){

    rotacionY[0][0] = cos(grados);
    rotacionY[0][1] = -sin(grados);
    rotacionY[0][2] = 0;
    rotacionY[0][3] = 0;
    rotacionY[1][0] = sin(grados);
    rotacionY[1][1] = cos(grados);
    rotacionY[1][2] = 0;
    rotacionY[1][3] = 0;
    rotacionY[2][0] = 0;
    rotacionY[2][1] = 0;
    rotacionY[2][2] = 1;
    rotacionY[2][3] = 0;
    rotacionY[3][0] = 0;
    rotacionY[3][1] = 0;
    rotacionY[3][2] = 0;
    rotacionY[3][3] = 1;
}


