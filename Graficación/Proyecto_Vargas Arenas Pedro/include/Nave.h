#ifndef NAVE_H
#define NAVE_H
#include "Linea.h"
#include "Punto.h"
#include "Triangulo.h"
#include "Cuadrado.h"


class Nave{

    private:
        Linea linea;
        Punto punto;
        Cuadrado cuadrado;
        Triangulo triangulo;
    public:
        Nave();
        ~Nave();
        void mostrarNave(int, int);

};

#endif // NAVE_H
