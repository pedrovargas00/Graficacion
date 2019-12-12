#include "Cubo.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

Cubo::Cubo(){
    //ctor
}

Cubo::~Cubo(){
    //dtor
}

void Cubo::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);
}

void Cubo::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    matriz.matrices(grados);
}

void Cubo::cuboUnitario(){

    puntos[0].setValues(0, 0, 0);
    puntos[1].setValues(1, 0, 0);
    puntos[2].setValues(1, 1, 0);
    puntos[3].setValues(0, 1, 0);
    puntos[4].setValues(0, 0, 1);
    puntos[5].setValues(1, 0, 1);
    puntos[6].setValues(1, 1, 1);
    puntos[7].setValues(0, 1, 1);
}

void Cubo::setUnitario(Punto p0, Punto p1, Punto p2, Punto p3, Punto p4, Punto p5, Punto p6, Punto p7){

    puntos[0].setValues(p0);
    puntos[1].setValues(p1);
    puntos[2].setValues(p2);
    puntos[3].setValues(p3);
    puntos[4].setValues(p4);
    puntos[5].setValues(p5);
    puntos[6].setValues(p6);
    puntos[7].setValues(p7);
}

Punto Cubo::getPunto(int i){

    return puntos[i];
}

void Cubo::puntosCubo(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Cubo::pCubo(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Cubo::pCuboRotaciones(int i){

    puntos[i].setValues(rotaciones.getPunto(0), rotaciones.getPunto(1), rotaciones.getPunto(2));
}

void Cubo::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Cubo::dibujarCubo(float x0, float y0, float z0, float x1, float y1, float z1){

    linea.setColor(color1, color2, color3);
    linea.setValues(x0, y0, z0, x1, y1, z1);
    linea.draw();
}

void Cubo::mostrar(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 8; i++){
        puntosCubo(i);
        matriz.operar(puntosF);
        pCubo(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 4; i < 7; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(7).getX(), getPunto(7).getY(), getPunto(7).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
    for(i = 0; i < 4; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+4).getX(), getPunto(i+4).getY(), getPunto(i+4).getZ());
}

void Cubo::mostrarRectangulo(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 8; i++){
        puntosCubo(i);
        matriz.operar(puntosF);
        pCubo(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 4; i < 7; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(7).getX(), getPunto(7).getY(), getPunto(7).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
    for(i = 0; i < 4; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+4).getX(), getPunto(i+4).getY(), getPunto(i+4).getZ());
}

void Cubo::setRotacionX(float x, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizX(x);
    for(i = 0; i < 8; i++){
        puntosCubo(i);
        rotaciones.operarX(puntosF);
        pCuboRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 4; i < 7; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(7).getX(), getPunto(7).getY(), getPunto(7).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
    for(i = 0; i < 4; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+4).getX(), getPunto(i+4).getY(), getPunto(i+4).getZ());

}

void Cubo::setRotacionY(float y, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizY(y);
    for(i = 0; i < 8; i++){
        puntosCubo(i);
        rotaciones.operarY(puntosF);
        pCuboRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 4; i < 7; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(7).getX(), getPunto(7).getY(), getPunto(7).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
    for(i = 0; i < 4; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+4).getX(), getPunto(i+4).getY(), getPunto(i+4).getZ());
}

void Cubo::setRotacionZ(float z, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizZ(z);
    for(i = 0; i < 8; i++){
        puntosCubo(i);
        rotaciones.operarZ(puntosF);
        pCuboRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 4; i < 7; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCubo(getPunto(7).getX(), getPunto(7).getY(), getPunto(7).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
    for(i = 0; i < 4; i++)
        dibujarCubo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+4).getX(), getPunto(i+4).getY(), getPunto(i+4).getZ());


}

int Cubo::getEje(){
    return eje;
}

void Cubo::setEje(int ej){
    eje = ej;
}

void Cubo::opcionEje(float grados, float tx, float ty, float tz, float e){

    switch(eje){
        case 1:
            setRotacionX(grados, tx, ty, tz, e);
            break;
        case 2:
            setRotacionY(grados, tx, ty, tz, e);
            break;
        case 3:
            setRotacionZ(grados, tx, ty, tz, e);
            break;
        default:
            break;
    }
}
