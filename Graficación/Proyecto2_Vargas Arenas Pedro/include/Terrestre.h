#ifndef TERRESTRE_H
#define TERRESTRE_H
#include "Linea.h"
#include "Cubo.h"
#include "Piramide.h"
#include "Cuadrado.h"
#include "Punto.h"

class Terrestre{

    private:
        Linea linea;
        Cubo cubo;
        Piramide piramide;
        Cuadrado cuadrado;
        Punto p0, p1, p2, p3, p4, p5, p6, p7;
    public:
        Terrestre();
        ~Terrestre();
        void mostrar(float, float, float, float, float);
        void rayo(float, float, float, float, float);
        void rayo2(float, float, float, float, float, float);
};

#endif // TERRESTRE_H
