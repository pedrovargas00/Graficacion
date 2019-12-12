#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Escenario.h"

Escenario::Escenario(){
}

Escenario::~Escenario(){
}

void Escenario::draw(){
/*15.5;
float EYE_Y = 0.4;
float EYE_Z = 12.5;*/
    glPushMatrix();
    laberinto.draw();
//    bonos[0].trasladar(15.5, 0.4, 10.5);
    bonos[0].draw();
    glPopMatrix();
}
bool Escenario::verificarCoordenadas(float x, float z){

    //printf("Recibe: %f, %f", x, z);
    if((x > 0 && z > 0) || (x == 0 && z > 0)){
            //printf("\n X : %f Z: %f \n", x, z);
            //setXZ();
        return laberinto.verificarCoordenadas(x,z);
        //c.verificarColision( x, z , tamXZ, XZ);
    }if((x < 0 && z > 0) || (x < 0 && z == 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            //setmenosXZ();
        return laberinto.verificarCoordenadas(x,z);
        //c.verificarColision( x, z, tammenosXZ, menosXZ );
    }if((x > 0 && z < 0) || (x > 0 && z == 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            //setXmenosZ();
        return laberinto.verificarCoordenadas(x,z);
         //return c.verificarColision( x, z, tamXmenosZ, XmenosZ );
    }if((x < 0 && z < 0) || (x == 0 && z < 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            //setmenosXmenosZ();
        return laberinto.verificarCoordenadas(x,z);
       // return c.verificarColision( x, z, tammenosXmenosZ, menosXmenosZ );
    }
}

bool Escenario::verificarColisionBono(float x, float z){ return true;}
