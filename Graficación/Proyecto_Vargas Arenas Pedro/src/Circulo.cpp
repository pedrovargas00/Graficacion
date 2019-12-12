#include "Circulo.h"
#include <stdio.h>
#include <math.h>

Circulo::Circulo(){

}

Circulo::~Circulo(){
    //dtor
}

void Circulo::setMatrizEscalamiento(float e){
    matrizOperacion.setEscalamiento(e);
}

void Circulo::setMatrizRotacion(float grados){
    matrizOperacion.setRotacion(grados);
}

void Circulo::setMatrizTraslacion(float x, float y){
    matrizOperacion.setTraslacion(x, y);
}

void Circulo::setOperar(float* p){
    matrizOperacion.operar(p);
}

void Circulo::dibujarCirculo(float x0, float y0, float x1, float y1){

    linea.bresenham(x0, y0, x1, y1);
}

void Circulo::unitarioCirculo(){

    float i;
    int n = 0;

    for(i = 0; i < 2*(atan(1)*4); i += 0.128){
        puntos[n].setValues(1*cos(i), 1*sin(i));
        n++;
    }
}

void Circulo::unitarioCirculo1(){

    float i;
    int n = 0;

    for(i = 0; i < 2*(atan(1)*4); i += 0.128){
        puntos[n].setValues(1*cos(i), 0.5*sin(i));
        n++;
    }
}

void Circulo::puntosCirculo(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = 1;
}

void Circulo::pCirculo(int i){

    puntos[i].setValues(matrizOperacion.puntosR[0], matrizOperacion.puntosR[1]);
}

Punto Circulo::getPunto(int i){
    return puntos[i];
}

void Circulo::mostrar(float escala, float rota, float x, float y){

    int i;

    unitarioCirculo();
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 50; i++){
        puntosCirculo(i);
        matrizOperacion.operar(puntosF);
        pCirculo(i);
    }
    for(i = 0; i < 49; i++)
        dibujarCirculo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarCirculo(getPunto(49).getX(), getPunto(49).getY(), getPunto(0).getX(), getPunto(0).getY());
}

void Circulo::mostrarOvalo(float escala, float rota, float x, float y){

    int i;

    unitarioCirculo1();
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 50; i++){
        puntosCirculo(i);
        matrizOperacion.operar(puntosF);
        pCirculo(i);
    }
    for(i = 0; i < 49; i++)
        dibujarCirculo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarCirculo(getPunto(49).getX(), getPunto(49).getY(), getPunto(0).getX(), getPunto(0).getY());
}
