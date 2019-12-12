#include "Cuadrado.h"
#include "stdio.h"

Cuadrado::Cuadrado(){
    //ctor
}

Cuadrado::~Cuadrado(){
    //dtor
}

void Cuadrado::setPuntosMatriz(float x0, float y0, float z0, float x1, float y1, float z1){

    matriz.setPuntos(x0, y0, z0, x1, y1, z1);
}

void Cuadrado::setMatriz(float x, float y, float z, float e, float grados){

    matriz.setTraslacion(x, y, z);
    matriz.setEscalamiento(e);
    matriz.matrices(grados);
}

void Cuadrado::cuadradoUnitario(){

    puntos[0].setValues(0, 0, 0);
    puntos[1].setValues(1, 0, 0);
    puntos[2].setValues(1, 1, 0);
    puntos[3].setValues(0, 1, 0);
}

void Cuadrado::setUnitario(Punto p0, Punto p1, Punto p2, Punto p3){

    puntos[0].setValues(p0);
    puntos[1].setValues(p1);
    puntos[2].setValues(p2);
    puntos[3].setValues(p3);
}

Punto Cuadrado::getPunto(int i){

    return puntos[i];

}

void Cuadrado::setColor(float c1, float c2, float c3){

    color1 = c1;
    color2 = c2;
    color3 = c3;
}

void Cuadrado::dibujarCuadrado(float x0, float y0, float z0, float x1, float y1, float z1){

    linea.setColor(color1, color2, color3);
    linea.setValues(x0, y0, z0, x1, y1, z1);
    linea.draw();
}

void Cuadrado::puntosCuadrado(int i){

    puntosF[0] = puntos[i].getX();
    puntosF[1] = puntos[i].getY();
    puntosF[2] = puntos[i].getZ();
    puntosF[3] = 1;
}

void Cuadrado::pCuadrado(int i){

    puntos[i].setValues(matriz.getPunto(0), matriz.getPunto(1), matriz.getPunto(2));
}

void Cuadrado::mostrar(float x, float y, float z, float e, float grados){

    int i;

    setMatriz(x, y, z, e, grados);
    matriz.operarRotacion();
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        matriz.operar(puntosF);
        pCuadrado(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Cuadrado::pCuadradoRotaciones(int i){

    puntos[i].setValues(rotaciones.getPunto(0), rotaciones.getPunto(1), rotaciones.getPunto(2));
}

void Cuadrado::setRotacionX(float x, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizX(x);
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        rotaciones.operarX(puntosF);
        pCuadradoRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Cuadrado::setRotacionY(float y, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizY(y);
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        rotaciones.operarY(puntosF);
        pCuadradoRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

void Cuadrado::setRotacionZ(float z, float tx, float ty, float tz, float e){

    int i;

    rotaciones.setTraslacion(tx, ty, tz);
    rotaciones.setEscalamiento(e);
    rotaciones.setMatrizZ(z);
    for(i = 0; i < 4; i++){
        puntosCuadrado(i);
        rotaciones.operarZ(puntosF);
        pCuadradoRotaciones(i);
    }
    for(i = 0; i < 3; i++)
        dibujarCuadrado(getPunto(i).getX(), getPunto(i).getY(), getPunto(i).getZ(), getPunto(i+1).getX(), getPunto(i+1).getY(), getPunto(i+1).getZ());
    dibujarCuadrado(getPunto(3).getX(), getPunto(3).getY(), getPunto(3).getZ(), getPunto(0).getX(), getPunto(0).getY(), getPunto(0).getZ());

}

//----------

int Cuadrado::getEje(){
    return eje;
}

void Cuadrado::setEje(int ej){
    eje = ej;
}

void Cuadrado::opcionEje(float grados, float tx, float ty, float tz, float e){

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
