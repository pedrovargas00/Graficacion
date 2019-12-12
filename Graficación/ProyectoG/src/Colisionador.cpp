#include "Colisionador.h"
#include <stdio.h>

Colisionador::Colisionador(){
}

Colisionador::~Colisionador(){
}

bool Colisionador::verificarColision(float x, float z, int tam, Cubo* arregloCubos){

    for(int i = 0; i < tam; i++){
        arregloCubos[i].calcularCoord();
        //arregloCubos[i].mostrarCoordenadas();
        if((arregloCubos[i].contienePunto(x, z)))
            return false;
    }
    return true;
}

bool Colisionador::verificarColisionBonos(float x, float z, Bonos* bono){

    for(int i = 0; i < 3; i++){
        bono[i].calcularCoord();
        if((bono[i].contienePunto(x, z)))
            return true;
    }
    return false;
}

bool Colisionador::verificarColisionDementor(float x, float z, int tam, Cubo* arreglo){

    bool opc;
    for(int i = 0; i < tam; i++){
        arreglo[i].calcularCoord();
        //arreglo[i].mostrarCoordenadas();
            if((arreglo[i].contienePunto(x, z)))
            return false;
    }
    return true;
}
