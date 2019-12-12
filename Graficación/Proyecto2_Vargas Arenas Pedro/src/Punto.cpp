#include "Punto.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

Punto::Punto(){
    coordenadas[0] = 0;
    coordenadas[1] = 0;
    coordenadas[2] = 0;
}

Punto::~Punto(){
}

void Punto::setValues(float x, float y, float z){

    coordenadas[0] = x;
    coordenadas[1] = y;
    coordenadas[2] = z;
}

void Punto::setValues(Punto p1){

    coordenadas[0] = p1.getX();
    coordenadas[1] = p1.getY();
    coordenadas[2] = p1.getZ();
}

float Punto::getX(){
    return coordenadas[0];
}

float Punto::getY(){
    return coordenadas[1];
}

float Punto::getZ(){
    return coordenadas[2];
}

float* Punto::getValues(){
    return coordenadas;
}

void Punto::dibujar(){

    glColor3f(1, 1, 1);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex3fv(coordenadas);
    glEnd();
}
