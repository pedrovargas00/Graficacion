#ifndef LINEA_H
#define LINEA_H
#include "Punto.h"

class Linea{
    private:
        //Punto *p1, *p2;
        Punto p1, p2;
    public:
        Linea();
        ~Linea();
        void dibujaLinea();
        void pixel(int, int, int);
        void bresenham(int, int, int, int);
        void setValues(int, int, int, int);
        int getValues();
        void setValues(Punto, Punto);
        //Punto getValues();
        void draw();
};

#endif // LINEA_H
