#ifndef BONOS_H
#define BONOS_H

class Bonos{
    private:
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        float mCoord[4][2];
        bool tocado;
    public:
        Bonos();
        virtual ~Bonos();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        void calcularCoord();
        bool contienePunto(float, float);
        void setTocado(bool);
        bool getTocado();
};

#endif // BONOS_H
