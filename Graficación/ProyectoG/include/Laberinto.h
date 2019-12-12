#ifndef LABERINTO_H
#define LABERINTO_H
#include "Cubo.h"
#include <Colisionador.h>
#include "Textura.h"

class Laberinto{

    private:
        Cubo cubo[85], XZ[19], menosXZ[22], menosXmenosZ[22], XmenosZ[23], cb;
        Bonos bonos[4];
        Colisionador c;
        FIBITMAP *dib1;
        GLuint texturas;
        Textura textura;
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados,tamXZ,tammenosXZ,tammenosXmenosZ,tamXmenosZ;
        void setXZ();
        void setmenosXmenosZ();
        void setmenosXZ();
        void setXmenosZ();
    public:
        Laberinto();
        virtual ~Laberinto();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        void piso();
        bool verificarCoordenadas(float, float);
        bool verificarCoordenadasBono(float, float);
        bool verificarColisionCopa(float, float);
        bool verificarCoordenadasDementor(float, float);
        Bonos* getBonos();
};

#endif // LABERINTO_H
