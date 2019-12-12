#ifndef MATRIZROTACION_H
#define MATRIZROTACION_H


class MatrizRotacion{
    private:
        float x[4][4];
        float y[4][4];
        float z[4][4];
        float mAux[4][4], resultado[4][4];
        float puntosR[4];
        float traslacion[4][4], escalamiento[4][4];
    public:
        MatrizRotacion();
        ~MatrizRotacion();
        void setMatrizX(float);
        void setMatrizY(float);
        void setMatrizZ(float);
        void operarX(float*);
        void operarY(float*);
        void operarZ(float*);
        void setTraslacion(float, float, float);
        void setEscalamiento(float);
        float getPunto(int);
};

#endif // MATRIZ_H
