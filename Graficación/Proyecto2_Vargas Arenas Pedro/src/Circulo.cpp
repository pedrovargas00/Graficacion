#include "Circulo.h"
#include <math.h>
#include <stdio.h>

Circulo::Circulo()
{
    //ctor
}

Circulo::~Circulo()
{
    //dtor
}

void Circulo::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Circulo::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);
}

void Circulo::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    matriz.matrices(grados);
}

void Circulo::circuloUnitario(){

    int n = 0;

    for(float i = 0; i < 2*(atan(1)*4); i += 0.128){
        puntos[n].setValues(1*cos(i), 1*sin(i), 0);
        n++;
    }
}

void Circulo::circuloUnitario1(){

    int n = 0;

    for(float i = 0; i < 2*(atan(1)*4); i += 0.128){
        puntos[n].setValues(0.5*cos(i), 0.5*sin(i), 0);
        n++;
    }
}

Punto Circulo::getPunto(int i){

    return puntos[i];
}

void Circulo::dibujarCirculo(float x0, float y0, float z0, float x1, float y1, float z1){

    linea.setValues(x0, y0, z0, x1, y1, z1);
    linea.draw();
}

void Circulo::puntosCirculo(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Circulo::pCirculo(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Circulo::mostrar(float x, float y, float z, float e, float grados){

    int i;

    circuloUnitario();
    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 50; i++){
        puntosCirculo(i);
        matriz.operar(puntosF);
        pCirculo(i);
    }
    for(i = 0; i < 49; i++)
        dibujarCirculo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCirculo(getPunto(49).getX(), getPunto(49).getY(), getPunto(49).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Circulo::mostrar1(float x, float y, float z, float e, float grados){

    int i;

    circuloUnitario1();
    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 50; i++){
        puntosCirculo(i);
        matriz.operar(puntosF);
        pCirculo(i);
    }
    for(i = 0; i < 49; i++)
        dibujarCirculo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCirculo(getPunto(49).getX(), getPunto(49).getY(), getPunto(49).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}
