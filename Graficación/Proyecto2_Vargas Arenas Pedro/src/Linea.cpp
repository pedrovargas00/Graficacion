#include "Linea.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

Linea::Linea(){
    //ctor
}

Linea::~Linea(){
    //dtor
}

void Linea::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);
}

void Linea::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    //matriz.setRotacion(x, y, z);
    matriz.matrices(grados);
}

void Linea::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Linea::setGrosor(float g){

    grosor = g;
}

void Linea::setValues(float x0, float y0, float z0, float x1, float y1, float z1){

    puntos[0].setValues(x0, y0, z0);
    puntos[1].setValues(x1, y1, z1);
}

Punto Linea::getPunto(int i){

    return puntos[i];
}


void Linea::pLinea(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Linea::puntosLinea(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Linea::draw(){

    glColor3f(color1, color2, color3);
    glLineWidth(grosor);
    glBegin(GL_LINES);
        glVertex3f(puntos[0].getX(), puntos[0].getY(), puntos[0].getZ());
        glVertex3f(puntos[1].getX(), puntos[1].getY(), puntos[1].getZ());
    glEnd();
}
void Linea::mostrar(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 2; i++){
        puntosLinea(i);
        matriz.operar(puntosF);
        pLinea(i);
    }
    draw();
}
