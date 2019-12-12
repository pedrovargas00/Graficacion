#include "Nave.h"

Nave::Nave(){
}

Nave::~Nave(){
    //dtor
}

void Nave::mostrarNave(int x, int y){

    cuadrado.mostrarRectangulo(200, 0, -600 + x, 400 + y, 0.5);
    cuadrado.mostrarRectangulo(60, 89.55, -560 + x, 540 + y, 0.5);
    cuadrado.mostrarRectangulo(100, 89.55, -520 + x, 500 + y, 0.4);
    cuadrado.mostrarRectangulo(60, 89.55, -560 + x, 300 + y, 0.5);
    cuadrado.mostrarRectangulo(100, 89.55, -520 + x, 300 + y, 0.4);
    cuadrado.mostrarRectangulo(80, 0, -500 + x, 430 + y, 0.5);
    cuadrado.mostrarCuadrado(40, 0, -640 + x, 430 + y);
    triangulo.mostrar(20, 199.50, -520 + x, 560 + y);
    triangulo.mostrar(20, 199.50, -520 + x, 360 + y);
    triangulo.mostrar(40, 199.50, -400 + x, 470 + y);
    linea.bresenham(-670 + x, 460 + y, -640 + x, 460 + y);
    linea.bresenham(-690 + x, 450 + y, -640 + x, 450 + y);
    linea.bresenham(-670 + x, 440 + y, -640 + x, 440 + y);
}
