#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Laberinto.h"
#include "Bonos.h"
#include "Dementor.h"
#include "Cubo.h"

class Escenario{

    private:
        Cubo cubo;
        Laberinto laberinto;
        float ojoX, ojoZ;
        Dementor dementor1, dementor2;
    public:
        Escenario();
        virtual ~Escenario();
        void draw();
        bool verificarCoordenadas(float, float);
        void verificarCoordenadasDementor();
        bool verificarCoordenadasBono(float,float);
        bool verificarCoordenadasCopa(float,float);
        void setCoordOjos(float, float);
        void verificarBono();
};

#endif // ESCENARIO_H
