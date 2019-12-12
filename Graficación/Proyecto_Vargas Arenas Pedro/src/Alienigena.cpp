#include "Alienigena.h"

Alienigena::Alienigena(){

}

Alienigena::~Alienigena(){
    //dtor
}

void Alienigena::mostrar(int x){


    linea.bresenham(-640 + x, -670, -650 + x, -700);
    linea.bresenham(-640 + x, -670, -630 + x, -700);
    linea.bresenham(-640 + x, -670, -640 + x, -640);
    linea.bresenham(-640 + x, -650, -610 + x, -650);
    linea.bresenham(-610 + x, -650, -660 + x, -660);
    linea.bresenham(-610 + x, -700, -610 + x, -640);
    triangulo.mostrar(10, 0, -615 + x, -640);
    circulo.mostrarOvalo(15, 0, -640 + x, -632);
}
