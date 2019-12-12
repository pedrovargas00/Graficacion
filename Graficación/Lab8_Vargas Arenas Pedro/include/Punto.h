#ifndef PUNTO_H
#define PUNTO_H
#include <GL/glut.h>
#include <stdlib.h>


class Punto{
    private:
        float coordenadas[2];
    public:
        Punto();
        ~Punto();
        void setValues(float, float);
        int getX();
        int getY();
        float* getValues();
        void draw();
};

#endif // PUNTO_H
