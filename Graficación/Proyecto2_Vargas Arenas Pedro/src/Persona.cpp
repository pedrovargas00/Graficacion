#include "Persona.h"

Persona::Persona(){
    //ctor
}

Persona::~Persona(){
    //dtor
}

void Persona::mostrar(float x, float y, float z, float e, float g){

    linea.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    circulo.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    linea.setColor(1, 1, 1);
    circulo.setColor(1, 1, 1);
    linea.setValues(0, 0, 0, 0, 1, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0, 0.7, 0, 0.5, 0.7, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0, 0.7, 0, -0.5, 0.7, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0, 0, 0, 0.5, -0.7, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    linea.setValues(0, 0, 0, -0.5, -0.7, 0);
    linea.mostrar(0 + x, 0 + y, 0 + z, 1 + e, 0 + g);
    circulo.mostrar1(0 + x,  0.7 + y, 0 + z, 1 + e, 0 + g);
}
