#include "Punto.h"

Punto::Punto(){
    coordenadas[0] = 0;
    coordenadas[1] = 0;
}

Punto::~Punto(){
}

void Punto::setValues(float x1, float y1){

    coordenadas[0] = x1;
    coordenadas[1] = y1;
}

int Punto::getX(){
    return coordenadas[0];
}

int Punto::getY(){
    return coordenadas[1];
}

float* Punto::getValues(){
    return coordenadas;
}

void Punto::draw(){

    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2fv(coordenadas);
    glEnd();
}
