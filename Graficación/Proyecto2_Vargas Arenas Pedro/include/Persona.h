#ifndef PERSONA_H
#define PERSONA_H
#include "Linea.h"
#include "Circulo.h"

class Persona{

    private:
        Linea linea;
        Circulo circulo;

    public:
        Persona();
        ~Persona();
        void mostrar(float, float, float, float, float);
};

#endif // PERSONA_H
