#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Laberinto.h"
#include "Bonos.h"
class Escenario
{
    private:
        Laberinto laberinto;
        Bonos bonos[4];
    public:
        Escenario();
        virtual ~Escenario();
        void draw();
        bool verificarCoordenadas(float, float);
        bool verificarColisionBono(float,float);
};

#endif // ESCENARIO_H
