#ifndef COLISIONADOR_H
#define COLISIONADOR_H

#include <Cubo.h>

class Colisionador
{
    private:

	public:
        Colisionador();
        virtual ~Colisionador();
        bool verificarColision(float , float, int, Cubo*);

};

#endif // COLISIONADOR_H
