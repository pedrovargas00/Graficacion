#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "Textura.h"
#ifndef CUBO_H
#define CUBO_H

class Cubo{

    private:
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        float mCoordenadas[4][2];
        FIBITMAP *dib1;
        GLuint texturas;
        Textura textura;
    public:
        Cubo();
        ~Cubo();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        void draw1();
        void mostrarCoordenadas();
        void calcularCoord();
        bool contienePunto(float, float);
        bool contienePuntoDementor(float, float);
};

#endif // CUBO_H
