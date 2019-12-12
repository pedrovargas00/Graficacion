#include "Muro.h"

Muro::Muro(){
    //ctor
}

Muro::~Muro(){
    //dtor
}

void Muro::mostrar(float x, float y, float z, float e, float g){

    linea.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    linea.setColor(0.4, 0.5, 0);
    linea.setValues(-15, 0 , 0, 15, 0, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(-15, 2, 0, 15, 2, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(-15, 4, 0, 15, 4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(-15, 4, 0, -15, 0, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(15, 4, 0, 15, 0, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
}

void Muro::mostrar2(float x, float y, float z, float e, float g){

    cubo.setPuntosMatriz(0, 0, 0, 0, -1, 0);
    cubo.setColor(0.4, 0.5, 0);
    p0.setValues(0, 0, 0);
    p1.setValues(1, 0, 0);
    p2.setValues(1, 0.4, 0);
    p3.setValues(0, 0.4, 0);
    p4.setValues(0, 0, -0.2);
    p5.setValues(1, 0, -0.2);
    p6.setValues(1, 0.4, -0.2);
    p7.setValues(0, 0.4, -0.2);
    cubo.setColor(0.4, 0.5, 0);
    cubo.setUnitario(p0, p1, p2, p3, p4, p5, p6, p7);
    cubo.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setPuntosMatriz(0, 0, 0, 0, -1, 0);
    linea.setColor(0.4, 0.5, 0);
    linea.setValues(0, 0, 0, 0, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0.2, 0, 0, 0.2, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0.4, 0, 0, 0.4, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0.6, 0, 0, 0.6, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0.8, 0, 0, 0.8, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(1, 0, 0, 1, 0.4, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
}
