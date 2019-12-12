#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{

    private:
        float a, b, c, d;
        float p1[] = {1, 1, 1};
        float p2[] = {2, 2, 2};
        float traslacion[4][4];
        float traslacionI[4][4];
        float rotacionX[4][4];
        float rotacionY[4][4];
        float rotacionZ[4][4];
        float rotacionXI[4][4];
        float rotacionYI[4][4];
    public:
        Matriz();
        ~Matriz();
        void puntos();
        void setTraslacion(float, float, float);
        void setTraslacionI();
        void setRotacionX();
        void setRotacionY();
        void setRotacionZ(float);
        void setRotacionXI();
        void setRotacionYI();
        float* operar(float);
};

#endif // MATRIZ_H
