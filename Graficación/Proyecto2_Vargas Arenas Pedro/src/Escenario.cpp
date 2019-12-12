#include "Escenario.h"

Escenario::Escenario(){
    //ctor
}

Escenario::~Escenario(){
    //dtor
}

void Escenario::mostrar(){

    linea.setPuntosMatriz(0, 0, 0, 0, 1, 0);
    linea.setColor(0.7, 0.5, 0.2);
    linea.setValues(16, 1, -12, 0, 5, -12);
    linea.mostrar(0, 0, 0, 1, 0);
    linea.setValues(0, 5, -12, -30, 1, -12);
    linea.mostrar(0, 0, 0, 1, 0);
    linea.setValues(0, 5, -12, -14, 0, -1);
    linea.mostrar(0, 0, 0, 1, 0);
    arbol.mostrar(0, 0, 0, 0, 0);
    arbol.mostrar(0, -2, 0, 0, 0);
    arbol.mostrar(2, -2, 0, 0, 0);
    arbol.mostrar(4, -2, 0, 0, 0);
    arbol.mostrar(0, -1, 0, 0, 0);
    arbol.mostrar(2, -1, 0, 0, 0);
    arbol.mostrar(4, -1, 0, 0, 0);
    arbol.mostrar(0, -3, 0, 0, 0);
    arbol.mostrar(2, -3, 0, 0, 0);
    arbol.mostrar(4, -3, 0, 0, 0);
    arbol.mostrar(0, -4, 0, 0, 0);
    arbol.mostrar(2, -4, 0, 0, 0);
    arbol.mostrar(4, -4, 0, 0, 0);
    arbol.mostrar(-2, -2, 0, 0, 0);
    arbol.mostrar(-4, -2, 0, 0, 0);
    arbol.mostrar(-6, -2, 0, 0, 0);
    arbol.mostrar(-2, -1, 0, 0, 0);
    arbol.mostrar(-4, -1, 0, 0, 0);
    arbol.mostrar(-6, -1, 0, 0, 0);
    arbol.mostrar(-2, -3, 0, 0, 0);
    arbol.mostrar(-4, -3, 0, 0, 0);
    arbol.mostrar(-6, -3, 0, 0, 0);
    arbol.mostrar(-2, -4, 0, 0, 0);
    arbol.mostrar(-4, -4, 0, 0, 0);
    arbol.mostrar(-6, -4, 0, 0, 0);
    arbol.mostrar(-2, 0, 0, 0, 0);
    arbol.mostrar(-4, 0, 0, 0, 0);
    arbol.mostrar(-6, 0, 0, 0, 0);
    arbol.mostrar(-8, -3, 0, 0, 0);
    arbol.mostrar(-10, -3, 0, 0, 0);
    arbol.mostrar(-12, -3, 0, 0, 0);
    arbol.mostrar(-8, -4, 0, 0, 0);
    arbol.mostrar(-10, -4, 0, 0, 0);
    arbol.mostrar(-12, -4, 0, 0, 0);
    arbol.mostrar(-8, -2, 0, 0, 0);
    arbol.mostrar(-10, -2, 0, 0, 0);
    arbol.mostrar(-12, -2, 0, 0, 0);
    nave.mostrar(0, 0, 0, 0, x*4);
    nave.mostrar2(9, 12, -6, 0, 0);
    nave.mostrar2(9, 12, -6, 0.8, x);
    nave.mostrar2(9, 12, -6, 0.8, -x);
    terrestre.mostrar(-8, 6, -2, -0.5, 40);
    terrestre.mostrar(-2, 7, -2, -0.5, 50);
    terrestre.mostrar(2, 8, -2, -0.5, 15);
    terrestre.rayo(-3 + y, 6.5 - y, 0, -0.8, 0);
    terrestre.rayo(-2.5 + y, 6.5 - y, 0, -0.8, 0);
    terrestre.rayo(-8.5 + y, 5.5 - y, 0, -0.9, 0);
    terrestre.rayo(-8 + y, 5.5 - y, 0, -0.9, 0);
    terrestre.rayo2(9, 12, -6, 0, 0, m);
    muro.mostrar(1, -2, 0, -0.3, 0);
    muro.mostrar(14, -7.5, -2, 0, 110);
    muro.mostrar(-30.8, -2, 0, -0.1, 0);
    muro.mostrar2(-20, -3, -4, e, 0);
    ciudad.mostrar(8, -10, 3, 0, 0);
    ciudad.mostrar(6, -12, 4, 0, 0);
    ciudad.mostrar(7, -14, 5, 0, 0);
    ciudad.mostrar(12, -12, 4, 0.5, 0);
    ciudad.mostrar(11, -14, 5, 0, 0);
    ciudad.mostrar(3, -9, 7, 0.5, 0);
    ciudad.mostrar(15, -15, 4, 0, 0);
    ciudad.mostrar(9, -3, 13, 0, 0);
    ciudad.mostrar(-2, -14, 5, 0, 0);
    ciudad.mostrar(-2, -14, 9, 0, 0);
    persona.mostrar(-15, -10, 5, -0.5, 0);
    persona.mostrar(-13, -8, 5, -0.5, 0);
    persona.mostrar(-15, -4, 5, -0.5, 0);
    persona.mostrar(-12, -9, 5, -0.5, 0);
    persona.mostrar(-10, -8, 5, -0.5, 0);
    x += 0.08;
    y += 0.3;
    e += 0.05;
    m -= 0.1;
    if(m < -40)
        m = 0;
    if(e > 6)
        e = 0;
    if(y > 25)
        y = 0;
}
