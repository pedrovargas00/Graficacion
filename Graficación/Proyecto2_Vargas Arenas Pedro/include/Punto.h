#ifndef PUNTO_H
#define PUNTO_H


class Punto{

    private:
        float coordenadas[3];
    public:
        Punto();
        ~Punto();
        void setValues(float, float, float);
        void setValues(Punto);
        float getX();
        float getY();
        float getZ();
        float* getValues();
        void dibujar();
};
#endif // PUNTO_H
