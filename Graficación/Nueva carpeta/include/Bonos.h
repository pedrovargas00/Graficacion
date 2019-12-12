#ifndef BONOS_H
#define BONOS_H


class Bonos
{
    private:
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        float coordX, coordZ;
    public:
        Bonos();
        virtual ~Bonos();
        void trasladar(float, float, float);
        void rotar(float, float, float, float);
        void escalar(float, float, float);
        void draw();
        void calcularCoord();
        bool contienePunto(float, float);
};

#endif // BONOS_H
