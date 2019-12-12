#include "Cuadrado.h"
#include <String.h>

Cuadrado::Cuadrado(){

}

Cuadrado::~Cuadrado(){

}

void Cuadrado::setMatrizEscalamiento(float e){
    matrizOperacion.setEscalamiento(e);
}

void Cuadrado::setMatrizRotacion(float grados){
    matrizOperacion.setRotacion(grados);
}

void Cuadrado::setMatrizTraslacion(float x, float y){
    matrizOperacion.setTraslacion(x, y);
}

void Cuadrado::setOperar(float* p){
    matrizOperacion.operar(p);
}

void Cuadrado::dibujarCuadrado(float x0, float y0, float x1, float y1){

    Linea linea;

    linea.bresenham(x0, y0, x1, y1);
}

void Cuadrado::unitarioCuadrado(){

    puntosC[0].setValues(0, 0);
    puntosC[1].setValues(1, 0);
    puntosC[2].setValues(1, 1);
    puntosC[3].setValues(0, 1);
}

void Cuadrado::unitarioCuadrado1(float m){

    puntosC[0].setValues(0, 0);
    puntosC[1].setValues(1, 0);
    puntosC[2].setValues(1, m);
    puntosC[3].setValues(0, m);
}

void Cuadrado::puntosCuadrado(int i){

    puntosF[0] = puntosC[i].getX();
    puntosF[1] = puntosC[i].getY();
    puntosF[2] = 1;
}

void Cuadrado::pCuadrado(int i){

    puntosC[i].setValues(matrizOperacion.puntosR[0], matrizOperacion.puntosR[1]);
}

Punto Cuadrado::getPunto(int i){
    return puntosC[i];
}

void Cuadrado::mostrarCuadrado(float escala, float rota, float x, float y){

    int i;

    unitarioCuadrado();
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        matrizOperacion.operar(puntosF);
        pCuadrado(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(0).getX(), getPunto(0).getY());
}

void Cuadrado::mostrarRectangulo(float escala, float rota, float x, float y, float m){

    int i;

    unitarioCuadrado1(m);
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        matrizOperacion.operar(puntosF);
        pCuadrado(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(0).getX(), getPunto(0).getY());
}
