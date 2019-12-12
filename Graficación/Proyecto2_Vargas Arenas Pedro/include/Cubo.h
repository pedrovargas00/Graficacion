#ifndef CUBO_H
#define CUBO_H
#include "Matriz.h"
#include "Punto.h"
#include "Linea.h"
#include "MatrizRotacion.h"

class Cubo{

    private:
        Matriz matriz;
        Linea linea;
        MatrizRotacion rotaciones;
        Punto puntos[8];
        float puntosF[4];
        int eje;
        float color1, color2, color3;
    public:
        Cubo();
        ~Cubo();
        void setColor(float, float, float);
        void opcionEje(float, float, float, float, float);
        void setRotacionX(float, float, float, float, float);
        void setRotacionY(float, float, float, float, float);
        void setRotacionZ(float, float, float, float, float);
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void cuboUnitario();
        void rectanguloUnitario(float);
        Punto getPunto(int);
        void dibujarCubo(float, float, float, float, float, float);
        void puntosCubo(int);
        void pCubo(int);
        int getEje();
        void setEje(int);
        void pCuboRotaciones(int);
        void mostrar(float, float, float, float, float);
        void mostrarRectangulo(float, float, float, float, float);
        void setUnitario(Punto, Punto, Punto, Punto, Punto, Punto, Punto, Punto);
};

#endif // CUBO_H
