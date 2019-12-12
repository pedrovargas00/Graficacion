#ifndef ALIENIGENA_H
#define ALIENIGENA_H
#include "Circulo.h"
#include "Triangulo.h"
#include "Linea.h"

class Alienigena{

    private:
        Linea linea;
        Circulo circulo;
        Triangulo triangulo;
    public:
        Alienigena();
        ~Alienigena();
        void mostrar(int);
};

#endif // ALIENIGENA_H
