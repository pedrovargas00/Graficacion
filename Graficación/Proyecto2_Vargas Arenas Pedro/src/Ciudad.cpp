#include "Ciudad.h"

Ciudad::Ciudad(){
    //ctor
}

Ciudad::~Ciudad(){
    //dtor
}

void Ciudad::mostrar(float x, float y, float z, float e, float g){

    p0.setValues(0, 0, 0);
    p1.setValues(2, 0, 0);
    p2.setValues(2, 4, 0);
    p3.setValues(0, 4, 0);
    p4.setValues(0, 0, -2);
    p5.setValues(2, 0, -2);
    p6.setValues(2, 4, -2);
    p7.setValues(0, 4, -2);
    cubo.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    cubo.setColor(0.7, 0.7, 0.6);
    cubo.setUnitario(p0, p1, p2, p3, p4, p5, p6,p7);
    cubo.mostrar(-5 + x, 4 + y, 2 + z, 1 + e, 0 + g);
    p0.setValues(0.25, 0, 0);
    p1.setValues(0.75, 0, 0);
    p2.setValues(0.75, 3, 0);
    p3.setValues(0.25, 3, 0);
    p4.setValues(1.50, 0, 0);
    p5.setValues(2, 0, 0);
    p6.setValues(2, 3, 0);
    p7.setValues(1.50, 3, 0);
    cuadrado.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    cuadrado.setColor(0.5, 1, 0.9);
    cuadrado.setUnitario(p0, p1, p2, p3);
    cuadrado.mostrar(-5 + x, 4 + y, 2 + z, 1 + e, 0 + g);
    cuadrado.setUnitario(p4, p5, p6, p7);
    cuadrado.mostrar(-5 + x, 4 + y, 2 + z, 1 + e, 0 + g);
    p0.setValues(2, 0, -0.5);
    p1.setValues(2, 0, -1.5);
    p2.setValues(2, 3, -1.5);
    p3.setValues(2, 3, -0.5);
    cuadrado.setUnitario(p0, p1, p2, p3);
    cuadrado.mostrar(-5 + x, 4 + y, 2 + z, 1 + e, 0 + g);
}
