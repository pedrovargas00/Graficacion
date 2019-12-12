#ifndef NAVE_H
#define NAVE_H
#include "Circulo.h"
#include "Piramide.h"
#include "Punto.h"

class Nave{

    private:
        Circulo circulo;
        Piramide piramide;
        Punto p0, p1, p2, p3, p4;
    public:
        Nave();
        ~Nave();
        void mostrar(float, float, float, float, float);
        void mostrar2(float, float, float, float, float);
};

#endif // NAVE_H
