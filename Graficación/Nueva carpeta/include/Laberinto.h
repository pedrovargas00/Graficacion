#ifndef LABERINTO_H
#define LABERINTO_H

#include "Cubo.h"
#include <Colisionador.h>


class Laberinto{

    private:
        Cubo cubo[85], XZ[19], menosXZ[22], menosXmenosZ[23], XmenosZ[23];
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados,tamXZ,tammenosXZ,tammenosXmenosZ,tamXmenosZ;
        void setXZ();
        void setmenosXmenosZ();
        void setmenosXZ();
        void setXmenosZ();
        Colisionador c;
    public:
        Laberinto();
        virtual ~Laberinto();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        bool verificarCoordenadas(float, float);
};


#endif // LABERINTO_H
