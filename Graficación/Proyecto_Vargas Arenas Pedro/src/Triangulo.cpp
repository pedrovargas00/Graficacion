#include "Triangulo.h"

Triangulo::Triangulo(){

}

Triangulo::~Triangulo(){
    //dtor
}

void Triangulo::setMatrizEscalamiento(float e){
    matrizOperacion.setEscalamiento(e);
}

void Triangulo::setMatrizRotacion(float grados){
    matrizOperacion.setRotacion(grados);
}

void Triangulo::setMatrizTraslacion(float x, float y){
    matrizOperacion.setTraslacion(x, y);
}

void Triangulo::dibujarTriangulo(float x0, float y0, float x1, float y1){

    Linea linea;

    linea.bresenham(x0, y0, x1, y1);
}

void Triangulo::unitarioTriangulo(){

    puntosT[0].setValues(0, 0);
    puntosT[1].setValues(1, 0);
    puntosT[2].setValues(0.5, 1);
}

void Triangulo::unitarioTriangulo1(){

    puntosT[0].setValues(0, 0);
    puntosT[1].setValues(1, 0);
    puntosT[2].setValues(0, 1);
}

void Triangulo::puntosTriangulo(int i){

    puntosF[0] = puntosT[i].getX();
    puntosF[1] = puntosT[i].getY();
    puntosF[2] = 1;
}

void Triangulo::pTriangulo(int i){

    puntosT[i].setValues(matrizOperacion.puntosR[0], matrizOperacion.puntosR[1]);
}

Punto Triangulo::getPunto(int i){
    return puntosT[i];
}

void Triangulo::mostrar(float escala, float rota, float x, float y){

    int i;

    unitarioTriangulo();
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        matrizOperacion.operar(puntosF);
        pTriangulo(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(0).getX(), getPunto(0).getY());
}

void Triangulo::mostrar1(float escala, float rota, float x, float y){

    int i;

    unitarioTriangulo1();
    setMatrizEscalamiento(escala);
    setMatrizRotacion(rota);
    setMatrizTraslacion(x, y);
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        matrizOperacion.operar(puntosF);
        pTriangulo(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i+1).getX(), getPunto(i+1).getY());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(0).getX(), getPunto(0).getY());
}
