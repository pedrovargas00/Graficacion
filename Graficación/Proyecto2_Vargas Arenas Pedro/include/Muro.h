#ifndef MURO_H
#define MURO_H
#include "Linea.h"
#include "Punto.h"
#include "Cubo.h"

class Muro{

    private:
        Punto p0, p1, p2, p3, p4, p5, p6, p7;
        Linea linea;
        Cubo cubo;
    public:
        Muro();
        ~Muro();
        void mostrar(float, float, float, float, float);
        void mostrar2(float, float, float, float, float);
};

#endif // MURO_H
