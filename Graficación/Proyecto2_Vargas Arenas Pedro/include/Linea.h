#ifndef LINEA_H
#define LINEA_H
#include "Punto.h"
#include "MatrizRotacion.h"
#include "Matriz.h"

class Linea{
    private:
        Matriz matriz;
        MatrizRotacion rotaciones;
        Punto puntos[2];
        float puntosF[4];
        float color1 = 1, color2 = 1, color3 = 1;
        float grosor = 1;
    public:
        Linea();
        ~Linea();
        void setColor(float, float, float);
        void setGrosor(float);
        void setValues(float, float, float, float, float, float);
        float getValues();
        void draw();
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void mostrar(float, float, float, float, float);
        void puntosLinea(int);
        void pLinea(int);
        Punto getPunto(int);
};

#endif // LINEA_H
