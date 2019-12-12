#include "Arbol.h"

Arbol::Arbol(){
    //ctor
}

Arbol::~Arbol(){
    //dtor
}

void Arbol::mostrar(float x, float y, float z, float e, float g){

    p0.setValues(0, 0, 0);
    p1.setValues(1, 0, 0);
    p2.setValues(1, 2, 0);
    p3.setValues(0, 2, 0);
    p4.setValues(0, 0, -1);
    p5.setValues(1, 0, -1);
    p6.setValues(1, 2, -1);
    p7.setValues(0, 2, -1);
    cubo.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    cubo.setUnitario(p0, p1, p2, p3, p4, p5, p6, p7);
    cubo.setColor(0.4, 0.2, 0);
    cubo.mostrar(7 + x, 4 + y, -2 + z, 0.5 + e, 0 + g);
    p0.setValues(-1, 2, 1);
    p1.setValues(2, 2, 1);
    p2.setValues(2, 2, -2);
    p3.setValues(-1, 2, -2);
    p4.setValues(0.5, 4, -0.5);
    piramide.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    piramide.setUnitario(p0, p1, p2, p3, p4);
    piramide.setColor(0.2, 0.7, 0.1);
    piramide.mostrar(7 + x, 4 + y, -1 + z, 0.5 + e, 0 + g);
}
