#include "Nave.h"

Nave::Nave(){
    //ctor
}

Nave::~Nave(){
    //dtor
}

void Nave::mostrar(float x, float y, float z, float e, float g){

    circulo.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    piramide.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    circulo.mostrar(-15 + x, 13 + y, -4 + z, 1.5 + e, 0 + g);
    circulo.mostrar(-10.5 + x, 13 + y, 4 + z, 0.6 + e, 0 + g);
    p0.setValues(0, 0, 0);
    p1.setValues(1, 0, 0);
    p2.setValues(1, -1, 0);
    p3.setValues(0, -1, 0);
    p4.setValues(0.5, -0.5, -1);
    piramide.setColor(1, 1, 1);
    piramide.setUnitario(p0, p1, p2, p3, p4);
    piramide.mostrar(-11.5 + x, 13.5 + y, 3 + z, 1 + e, 0 + g);
}

void Nave::mostrar2(float x, float y, float z, float e, float g){

    piramide.setEje(3);
    piramide.setColor(0.3, 0.5, 0.6);
    p0.setValues(-1, -1, -3);
    p1.setValues(1, -1, -3);
    p2.setValues(1, 1, -3);
    p3.setValues(-1, 1, -3);
    p4.setValues(0, 0, 0);
    piramide.setUnitario(p0, p1, p2, p3, p4);
    piramide.opcionEje(0 + g, 0 + x, 0 + y, 0 + z, 1 + e);
}
