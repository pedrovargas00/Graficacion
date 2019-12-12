#include "Triangulo.h"
#include "stdio.h"

Triangulo::Triangulo(){
    //ctor
}

Triangulo::~Triangulo(){
    //dtor
}

void Triangulo::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);

}

void Triangulo::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    matriz.matrices(grados);
}

void Triangulo::trianguloUnitario(){

    puntos[0].setValues(0, 0, 0);
    puntos[1].setValues(1, 0, 0);
    puntos[2].setValues(0.5, 1, 0);
}

void Triangulo::setUnitario(Punto p0, Punto p1, Punto p2){

    puntos[0].setValues(p0);
    puntos[1].setValues(p1);
    puntos[2].setValues(p2);
}

Punto Triangulo::getPunto(int i){

    return puntos[i];
}

void Triangulo::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Triangulo::dibujarTriangulo(float x0, float y0, float z0, float x1, float y1, float z1){

    linea.setColor(color1, color2, color3);
    linea.setValues(x0, y0, z0, x1, y1, z1);
    linea.draw();
}

void Triangulo::puntosTriangulo(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Triangulo::pTriangulo(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Triangulo::pTrianguloRotaciones(int i){

     puntos[i].setValues(rotaciones.getPunto(0), rotaciones.getPunto(1), rotaciones.getPunto(2));
}

void Triangulo::mostrar(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        matriz.operar(puntosF);
        pTriangulo(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(2).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Triangulo::setRotacionX(float x, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizX(x);
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        rotaciones.operarX(puntosF);
        pTrianguloRotaciones(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(2).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
}

void Triangulo::setRotacionY(float y, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizY(y);
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        rotaciones.operarY(puntosF);
        pTrianguloRotaciones(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(2).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Triangulo::setRotacionZ(float z, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizZ(z);
    for(i = 0; i < 3; i++){
        puntosTriangulo(i);
        rotaciones.operarZ(puntosF);
        pTrianguloRotaciones(i);
    }
    for(i = 0; i < 2; i++)
        dibujarTriangulo(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarTriangulo(getPunto(2).getX(), getPunto(2).getY(), getPunto(2).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());
}

//----------

int Triangulo::getEje(){
    return eje;
}

void Triangulo::setEje(int ej){
    eje = ej;
}

void Triangulo::opcionEje(float grados, float tx, float ty, float tz, float e){

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
