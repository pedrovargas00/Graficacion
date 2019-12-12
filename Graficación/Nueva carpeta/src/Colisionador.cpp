#include "Colisionador.h"

#include <stdio.h>
Colisionador::Colisionador(){
}

Colisionador::~Colisionador(){
}

bool Colisionador::verificarColision(float x, float z, int tam, Cubo* arregloCubos){

    for(int i=0; i<tam; i++){
       // printf("i: %d",i);
        arregloCubos[i].calcularCoord();
        if((arregloCubos[i].contienePunto(x,z)))
            return false;
    }
    return true;
}
