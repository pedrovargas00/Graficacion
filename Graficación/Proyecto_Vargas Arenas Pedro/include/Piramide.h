#ifndef PIRAMIDE_H
#define PIRAMIDE_H
#include "Linea.h"
#include "Triangulo.h"

class Piramide{

    private:
        Linea linea;
        Triangulo triangulo;
    public:
        Piramide();
        ~Piramide();
        void piso();
        void mostrar(int, int);
        void media();
};

#endif // PIRAMIDE_H
