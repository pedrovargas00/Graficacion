#include "Escenario.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Linea.h"
#include "Punto.h"

Escenario::Escenario(){
}

Escenario::~Escenario(){
    //dtor
}

void Escenario::mostrar(){


    for(float i = 0; i < 700; i += 3){
        glClear(GL_COLOR_BUFFER_BIT);
        piramide.piso();
        piramide.mostrar(0, 0);
        piramide.media();
        piramide.mostrar(-500, 0);
        luna.mostrar();
        alienigena.mostrar(0);
        alienigena.mostrar(50);
        alienigena.mostrar(100);
        nave.mostrarNave(i, 0);
        nave.mostrarNave(200 + i, -200);
        nave.mostrarNave(i, -400);
        glFlush();
    }
}
