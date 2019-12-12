#ifndef COLISIONADOR_H
#define COLISIONADOR_H

#include "Cubo.h"
#include "Bonos.h"

class Colisionador{

    private:

	public:
        Colisionador();
        virtual ~Colisionador();
        bool verificarColision(float , float, int, Cubo*);
        bool verificarColisionBonos(float, float , Bonos*);
        bool verificarColisionDementor(float x, float z, int tam, Cubo *arreglo);
};

#endif // COLISIONADOR_H
