#ifndef CUBO_H
#define CUBO_H

class Cubo{

    private:
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        float mCoordenadas[4][2];
    public:
        Cubo();
        ~Cubo();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        void calcularCoord();
        bool contienePunto(float, float);
};

#endif // CUBO_H
