#ifndef ESCENARIO_H
#define ESCENARIO_H
#include "Nave.h"
#include "Piramide.h"
#include "Alienigena.h"
#include "Luna.h"

class Escenario{
    private:
        Nave nave;
        Piramide piramide;
        Alienigena alienigena;
        Luna luna;
    public:
        Escenario();
        ~Escenario();
        void mostrar();
};

#endif // ESCENARIO_H
