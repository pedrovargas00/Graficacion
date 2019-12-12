#ifndef VARITA_H
#define VARITA_H
#include "Objetos.h"

class Varita{

    private:
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        Objetos objeto;
        GLuint varita;
    public:
        Varita();
        ~Varita();
        void setTraslacion(float, float, float);
        void setRotacion(float, float, float, float);
        void setEscala(float, float, float);
        void draw();
};

#endif // VARITA_H
