#ifndef ESCENARIO_H
#define ESCENARIO_H
#include "Nave.h"
#include "Ciudad.h"
#include "Terrestre.h"
#include "Arbol.h"
#include "Muro.h"
#include "Persona.h"
#include "Linea.h"

class Escenario{

    private:
        Linea linea;
        Nave nave;
        Ciudad ciudad;
        Terrestre terrestre;
        Arbol arbol;
        Persona persona;;
        Muro muro;
        float x = 0, y = 0, e = 0, m = 0;
    public:
        Escenario();
        ~Escenario();
        void mostrar();
};

#endif // ESCENARIO_H
