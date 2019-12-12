#include "Piramide.h"

Piramide::Piramide(){
    //ctor
}

Piramide::~Piramide(){
    //dtor
}

void Piramide::piso(){
    linea.bresenham(-700, -700, 700, -700);
}

void Piramide::mostrar(int x, int y){

    triangulo.mostrar(400, 0, 270 + x, -700);
    linea.bresenham(470 + x, -300 + y, 570 + x, -700);
}

void Piramide::media(){
    linea.bresenham(150, -700, 300, -400);
    linea.bresenham(300, -400, 370, -500);
    linea.bresenham(300, -400, 330, -570);
}
