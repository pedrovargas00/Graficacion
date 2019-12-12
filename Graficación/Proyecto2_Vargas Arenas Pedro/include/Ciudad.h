#ifndef CIUDAD_H
#define CIUDAD_H
#include "Linea.h"
#include "Cubo.h"
#include "Cuadrado.h"
#include "Piramide.h"

class Ciudad{

    private:
        Punto p0, p1, p2, p3, p4, p5, p6, p7;
        Cubo cubo;
        Cuadrado cuadrado;
    public:
        Ciudad();
        ~Ciudad();
        void mostrar(float, float, float, float, float);
};

#endif // CIUDAD_H
