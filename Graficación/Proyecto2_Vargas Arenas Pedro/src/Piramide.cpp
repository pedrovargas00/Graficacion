#include "Piramide.h"
#include <stdio.h>

Piramide::Piramide(){
    //ctor
}

Piramide::~Piramide(){
    //dtor
}

void Piramide::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);
}

void Piramide::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    matriz.matrices(grados);
}

void Piramide::piramideUnitario(){

    puntos[0].setValues(0, 0, 0);
    puntos[1].setValues(1, 0, 0);
    puntos[2].setValues(1, 0, 1);
    puntos[3].setValues(0, 0, 1);
    puntos[4].setValues(0.5, 0.5, 0.5);
}

void Piramide::setUnitario(Punto p0, Punto p1, Punto p2, Punto p3, Punto p4){

    puntos[0].setValues(p0);
    puntos[1].setValues(p1);
    puntos[2].setValues(p2);
    puntos[3].setValues(p3);
    puntos[4].setValues(p4);
}

Punto Piramide::getPunto(int i){

    return puntos[i];
}

void Piramide::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Piramide::dibujarPiramide(float x0, float y0, float z0, float x1, float y1, float z1){

    linea.setColor(color1, color2, color3);
    linea.setValues(x0, y0, z0, x1, y1, z1);
    linea.draw();
}

void Piramide::puntosPiramide(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Piramide::pPiramide(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Piramide::mostrar(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 5; i++){
        puntosPiramide(i);
        matriz.operar(puntosF);
        pPiramide(i);
    }
    for(i = 0; i < 3; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarPiramide(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 0; i < 4; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
}

void Piramide::pPiramideRotaciones(int i){

    puntos[i].setValues(rotaciones.getPunto(0), rotaciones.getPunto(1), rotaciones.getPunto(2));
}

void Piramide::setRotacionX(float x, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizX(x);
    for(i = 0; i < 5; i++){
        puntosPiramide(i);
        rotaciones.operarX(puntosF);
        pPiramideRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarPiramide(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 0; i < 4; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());
}

void Piramide::setRotacionY(float y, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizY(y);
    for(i = 0; i < 5; i++){
        puntosPiramide(i);
        rotaciones.operarY(puntosF);
        pPiramideRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarPiramide(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 0; i < 4; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());

}

void Piramide::setRotacionZ(float z, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizZ(z);
    for(i = 0; i < 5; i++){
        puntosPiramide(i);
        rotaciones.operarZ(puntosF);
        pPiramideRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarPiramide(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
    for(i = 0; i < 4; i++)
        dibujarPiramide(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(4).getX(), getPunto(4).getY(), getPunto(4).getZ());

}

//----------

int Piramide::getEje(){
    return eje;
}

void Piramide::setEje(int ej){
    eje = ej;
}

void Piramide::opcionEje(float grados, float tx, float ty, float tz, float e){

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
