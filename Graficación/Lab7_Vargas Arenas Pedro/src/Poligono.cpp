#include <math.h>
#include <stdlib.h>
#include "Poligono.h"
#include "Punto.h"
#include "Linea.h"
#include <String.h>
#include <stdio.h>

Poligono::Poligono(){

}

Poligono::~Poligono(){
    //dtor
}

//int* Poligono::getPuntos(){}

void Poligono::setPuntosT(int x0, int y0, int x1, int y1, int x2, int y2){

    puntosT[0] = x0;
    puntosT[1] = y0;
    puntosT[2] = x1;
    puntosT[3] = y1;
    puntosT[4] = x2;
    puntosT[5] = y2;
}

void Poligono::setPuntosC(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3){

    puntosC[0] = x0;
    puntosC[1] = y0;
    puntosC[2] = x1;
    puntosC[3] = y1;
    puntosC[4] = x2;
    puntosC[5] = y2;
    puntosC[6] = x3;
    puntosC[7] = y3;
}

void Poligono::dibujarTriangulo(int x0, int y0, int x1, int y1, int x2, int y2){

    Linea linea;

    setPuntosT(x0, y0, x1, y1, x2, y2);
    linea.bresenham(x0, y0, x1, y1);
    linea.bresenham(x0, y0, x2, y2);
    linea.bresenham(x1, y1, x2, y2);

}

void Poligono::dibujarCuadrado(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3){

    Linea linea;

    setPuntosC(x0, y0, x1, y1, x2, y2, x3, y3);
    linea.bresenham(x0, y0, x1, y1);
    linea.bresenham(x1, y1, x2, y2);
    linea.bresenham(x2, y2, x3, y3);
    linea.bresenham(x3, y3, x0, y0);

}

void Poligono::rotar(int angulo){

    int i = 2;
    int j = 3;

    /* for(i = 2; i < 8; i++){
        puntosC[i] = (puntosC[i] * cos(angulo)) - (puntosC[++i] * sin(angulo));
        i++;
        puntosC[i] = (puntosC[i] * cos(angulo)) + (puntosC[++i] * sin(angulo));
    }
    dibujarCuadrado(puntosC[0], puntosC[1], puntosC[2], puntosC[3], puntosC[4], puntosC[5], puntosC[6], puntosC[7]);*/

    for(i = 2; i < 6; i++){
        if((i%2) == 0)
            puntosT[i] = (puntosT[i] * cos(angulo)) - (puntosT[j] * sin(angulo));
        printf("\nI: %d, J: %d", i, j);
        if((i%2) != 0){
            printf("\nEntró");
            puntosT[i] = (puntosT[i-1] * sin(angulo)) + (puntosT[j] * cos(angulo));
            j += 2;
        }
    }
    dibujarTriangulo(puntosT[0], puntosT[1], puntosT[2], puntosT[3], puntosT[4], puntosT[5]);
}

void Poligono::escalar(float escala){

    int i;

    for(i = 0; i < 8; i++)
        puntosC[i] = puntosC[i] * escala;
    dibujarCuadrado(puntosC[0], puntosC[1], puntosC[2], puntosC[3], puntosC[4], puntosC[5], puntosC[6], puntosC[7]);

    for(i = 0; i < 6; i++)
        puntosT[i] = puntosT[i] * escala;
    dibujarTriangulo(puntosT[0], puntosT[1], puntosT[2], puntosT[3], puntosT[4], puntosT[5]);

}

void Poligono::trasladar(int traslado){

    int i;

    for(i = 0; i < 8; i++)
        puntosC[i] = puntosC[i] + traslado;
    dibujarCuadrado(puntosC[0], puntosC[1], puntosC[2], puntosC[3], puntosC[4], puntosC[5], puntosC[6], puntosC[7]);

    for(i = 0; i < 6; i++)
        puntosT[i] = puntosT[i] + traslado;
    dibujarTriangulo(puntosT[0], puntosT[1], puntosT[2], puntosT[3], puntosT[4], puntosT[5]);
}
