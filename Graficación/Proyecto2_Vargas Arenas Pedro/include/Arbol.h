#ifndef ARBOL_H
#define ARBOL_H
#include "Punto.h"
#include "Piramide.h"
#include "Cubo.h"

class Arbol{

    private:
        Punto p0, p1, p2, p3, p4, p5, p6, p7;
        Cubo cubo;
        Piramide piramide;
    public:
        Arbol();
        ~Arbol();
        void inicia();
        void mostrar(float, float, float, float, float);
};

#endif // ARBOL_H
