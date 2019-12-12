#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Laberinto.h"
#include <stdio.h>

Laberinto::Laberinto(){
    sx = 1;    sy = 1;    sz = 1;
    tx = 0;    ty = 0;    tz = 0;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;
    tamXZ = 18; tammenosXZ = 22; tammenosXmenosZ = 23;  tamXmenosZ = 23;
}

Laberinto::~Laberinto(){
}

void Laberinto::escalar(float x, float y, float z){

    sx = x;
    sy = y;
    sz = z;
}

void Laberinto::trasladar(float x, float y, float z){

    tx = x;
    ty = y;
    tz = z;
}

void Laberinto::rotar(float grad, float x, float y,float z){

    grados = grad;
    rx = x;
    ry = y;
    rz = z;
}

void Laberinto::draw(){

    glColor3f(0, 1, 0.5);

    glPushMatrix();

    glTranslatef(tx, ty, tz);
    glRotatef(grados, rx, ry, rz);
    glScalef(sx, sy, sz);

    cubo[0].trasladar(-1.5, 0, 1);
    cubo[0].rotar(90, 0, 1, 0);
    cubo[0].escalar(0.5, 2, 1);
    cubo[0].draw();

    cubo[1].trasladar(2, 0, 0);
    cubo[1].escalar(1, 2, 0.5);
    cubo[1].draw();

    cubo[2].trasladar(2.5, 0, 0);
    cubo[2].escalar(2.5, 2, 0.5);
    cubo[2].rotar(90, 0, 1, 0);
    cubo[2].draw();
/*
    cubo[61].trasladar(2, 0, 0);
    cubo[61].escalar(1, 2, 1);
    cubo[61].draw();
*/
    cubo[3].trasladar(-4, 0, 2);
    cubo[3].escalar(2, 2, 1);
    cubo[3].rotar(90, 0, 1, 0);
    cubo[3].draw();

    cubo[4].trasladar(-4, 0, 2);
    cubo[4].escalar(4, 2, 1);
    cubo[4].draw();

    cubo[62].trasladar(0, 0, 2);
    cubo[62].escalar(5, 2, 1);
    cubo[62].draw();

    cubo[5].trasladar(4, 0, 2);
    cubo[5].escalar(2, 2, 1);
    cubo[5].rotar(90, 0, 1, 0);
    cubo[5].draw();
//
    cubo[6].trasladar(-2, 0, 2);
    cubo[6].escalar(2.5, 2, 0.5);
    cubo[6].rotar(90, 0, 1, 0);
    cubo[6].draw();
//
    cubo[63].trasladar(-2, 0, 0);
    cubo[63].escalar(2.5, 2, 0.5);
    cubo[63].rotar(90, 0, 1, 0);
    cubo[63].draw();

    cubo[7].trasladar(-2, 0, -3);
    cubo[7].escalar(2, 2, 0.5);
    cubo[7].draw();

    cubo[64].trasladar(0, 0, -3);
    cubo[64].escalar(3, 2, 0.5);
    cubo[64].draw();

    cubo[8].trasladar(4, 0, -1);
    cubo[8].escalar(4, 2, 1);
    cubo[8].rotar(90, 0, 1, 0);
    cubo[8].draw();

    cubo[9].trasladar(-4, 0, -5);
    cubo[9].escalar(4, 2, 1);
    cubo[9].draw();

    cubo[65].trasladar(0, 0, -5);
    cubo[65].escalar(4, 2, 1);
    cubo[65].draw();

    cubo[10].trasladar(-4, 0, -1);
    cubo[10].escalar(3, 2, 1);
    cubo[10].rotar(90, 0, 1, 0);
    cubo[10].draw();

    cubo[11].trasladar(-5, 0, -7);
    cubo[11].escalar(5, 2, 1);
    cubo[11].draw();

    cubo[66].trasladar(0, 0, -7);
    cubo[66].escalar(1, 2, 1);
    cubo[66].draw();

    cubo[12].trasladar(2, 0, -7);
    cubo[12].escalar(5, 2, 1);
    cubo[12].draw();

    cubo[13].trasladar(6, 0, 5);
    cubo[13].escalar(5, 2, 1);
    cubo[13].rotar(90, 0, 1, 0);
    cubo[13].draw();

    cubo[67].trasladar(6, 0, 0);
    cubo[67].escalar(6, 2, 1);
    cubo[67].rotar(90, 0, 1, 0);
    cubo[67].draw();

    cubo[14].trasladar(0, 0, 4);
    cubo[14].escalar(6, 2, 1);
    cubo[14].draw();

    cubo[15].trasladar(-5, 0, 4);
    cubo[15].escalar(4, 2, 1);
    cubo[15].draw();

    cubo[16].trasladar(-6, 0, 5);
    cubo[16].escalar(3, 2, 1);
    cubo[16].rotar(90, 0, 1, 0);
    cubo[16].draw();

    cubo[17].trasladar(-6, 0, 0);
    cubo[17].escalar(7, 2, 1);
    cubo[17].rotar(90, 0, 1, 0);
    cubo[17].draw();

    cubo[18].trasladar(-8, 0, 0);
    cubo[18].escalar(3, 2, 1);
    cubo[18].draw();

    cubo[19].trasladar(-8, 0, 0);
    cubo[19].escalar(3, 2, 1);
    cubo[19].rotar(90, 0, 1, 0);
    cubo[19].draw();

    cubo[20].trasladar(-8, 0, -4);
    cubo[20].escalar(4, 2, 1);
    cubo[20].rotar(90, 0, 1, 0);
    cubo[20].draw();

    cubo[21].trasladar(-8, 0, -9);
    cubo[21].escalar(8, 2, 1);
    cubo[21].draw();

    cubo[68].trasladar(0, 0, -9);
    cubo[68].escalar(9, 2, 1);
    cubo[68].draw();

    cubo[22].trasladar(8, 0, -4);
    cubo[22].escalar(4, 2, 1);
    cubo[22].rotar(90, 0, 1, 0);
    cubo[22].draw();

    cubo[23].trasladar(8, 0, 6);
    cubo[23].escalar(7, 2, 1);
    cubo[23].rotar(90, 0, 1, 0);
    cubo[23].draw();

    cubo[69].trasladar(8, 0, 0);
    cubo[69].escalar(1, 2, 1);
    cubo[69].draw();

    cubo[24].trasladar(-4, 0, 6);
    cubo[24].escalar(4, 2, 1);
    cubo[24].draw();

    cubo[70].trasladar(0, 0, 6);
    cubo[70].escalar(9, 2, 1);
    cubo[70].draw();

    cubo[25].trasladar(-8, 0, 6);
    cubo[25].escalar(3, 2, 1);
    cubo[25].draw();

    cubo[26].trasladar(-8, 0, 6);
    cubo[26].escalar(4, 2, 1);
    cubo[26].rotar(90, 0, 1, 0);
    cubo[26].draw();

    cubo[27].trasladar(-10, 0, 8);
    cubo[27].escalar(8, 2, 1);
    cubo[27].rotar(90, 0, 1, 0);
    cubo[27].draw();

    cubo[71].trasladar(-10, 0, 0);
    cubo[71].escalar(5, 2, 1);
    cubo[71].rotar(90, 0, 1, 0);
    cubo[71].draw();

    cubo[28].trasladar(-10, 0, 8);
    cubo[28].escalar(10, 2, 1);
    cubo[28].draw();

    cubo[72].trasladar(0, 0, 8);
    cubo[72].escalar(11, 2, 1);
    cubo[72].draw();

    cubo[29].trasladar(10, 0, 9);
    cubo[29].escalar(9, 2, 1);
    cubo[29].rotar(90, 0, 1, 0);
    cubo[29].draw();

    cubo[73].trasladar(10, 0, 0);
    cubo[73].escalar(1, 2, 1);
    cubo[73].rotar(90, 0, 1, 0);
    cubo[73].draw();

    cubo[30].trasladar(-2, 0, 8);
    cubo[30].escalar(1, 2, 1);
    cubo[30].rotar(90, 0, 1, 0);
    cubo[30].draw();

    cubo[31].trasladar(-11, 0, -7);
    cubo[31].escalar(2, 2, 1);
    cubo[31].draw();

    cubo[32].trasladar(-10, 0, -7);
    cubo[32].escalar(4, 2, 1);
    cubo[32].rotar(90, 0, 1, 0);
    cubo[32].draw();

    cubo[33].trasladar(-9, 0, -11);
    cubo[33].escalar(9, 2, 1);
    cubo[33].draw();

    cubo[34].trasladar(1, 0, -11);
    cubo[34].escalar(10, 2, 1);
    cubo[34].draw();

    cubo[35].trasladar(10, 0, -3);
    cubo[35].escalar(7, 2, 1);
    cubo[35].rotar(90, 0, 1, 0);
    cubo[35].draw();

    cubo[36].trasladar(8, 0, -3);
    cubo[36].escalar(4, 2, 1);
    cubo[36].draw();


    cubo[37].trasladar(-12, 0, 10);
    cubo[37].escalar(12, 2, 1);
    cubo[37].draw();

    cubo[74].trasladar(0, 0, 10);
    cubo[74].escalar(12, 2, 1);
    cubo[74].draw();

    cubo[38].trasladar(-12, 0, 11);
    cubo[38].escalar(10, 2, 1);
    cubo[38].rotar(90, 0, 1, 0);
    cubo[38].draw();

    cubo[39].trasladar(-12, 0, 0);
    cubo[39].escalar(9, 2, 1);
    cubo[39].rotar(90, 0, 1, 0);
    cubo[39].draw();

    cubo[40].trasladar(-12, 0, -10);
    cubo[40].escalar(3, 2, 1);
    cubo[40].rotar(90, 0, 1, 0);
    cubo[40].draw();

    cubo[41].trasladar(-12, 0, -13);
    cubo[41].escalar(12, 2, 1);
    cubo[41].draw();

    cubo[75].trasladar(0, 0, -13);
    cubo[75].escalar(12, 2, 1);
    cubo[75].draw();

    cubo[42].trasladar(12, 0, -10);
    cubo[42].escalar(3, 2, 1);
    cubo[42].rotar(90, 0, 1, 0);
    cubo[42].draw();

    cubo[43].trasladar(12, 0, 0);
    cubo[43].escalar(9, 2, 1);
    cubo[43].rotar(90, 0, 1, 0);
    cubo[43].draw();

    cubo[76].trasladar(12, 0, 3);
    cubo[76].escalar(3, 2, 1);
    cubo[76].rotar(90, 0, 1, 0);
    cubo[76].draw();

    cubo[44].trasladar(12, 0, 11);
    cubo[44].escalar(7, 2, 1);
    cubo[44].rotar(90, 0, 1, 0);
    cubo[44].draw();

    cubo[45].trasladar(-14, 0, 12);
    cubo[45].escalar(13, 2, 1);
    cubo[45].draw();

    cubo[46].trasladar(-14, 0, 12);
    cubo[46].escalar(3, 2, 1);
    cubo[46].rotar(90, 0, 1, 0);
    cubo[46].draw();

    cubo[47].trasladar(-14, 0, 8);
    cubo[47].escalar(8, 2, 1);
    cubo[47].rotar(90, 0, 1, 0);
    cubo[47].draw();

    cubo[77].trasladar(-14, 0, 0);
    cubo[77].escalar(15, 2, 1);
    cubo[77].rotar(90, 0, 1, 0);
    cubo[77].draw();

    cubo[48].trasladar(-14, 0, -15);
    cubo[48].escalar(12, 2, 1);
    cubo[48].draw();

    cubo[49].trasladar(-7, 0, -14);
    cubo[49].escalar(1, 2, 1);
    cubo[49].draw();

    cubo[50].trasladar(0, 0, -15);
    cubo[50].escalar(15, 2, 1);
    cubo[50].draw();

    cubo[78].trasladar(-1, 0, -15);
    cubo[78].escalar(1, 2, 1);
    cubo[78].draw();

    cubo[51].trasladar(14, 0, -6);
    cubo[51].escalar(8, 2, 1);
    cubo[51].rotar(90, 0, 1, 0);
    cubo[51].draw();

    cubo[52].trasladar(14, 0, 0);
    cubo[52].escalar(5, 2, 1);
    cubo[52].rotar(90, 0, 1, 0);
    cubo[52].draw();

    cubo[79].trasladar(14, 0, 7);
    cubo[79].escalar(7, 2, 1);
    cubo[79].rotar(90, 0, 1, 0);
    cubo[79].draw();

    cubo[53].trasladar(13, 0, -9);
    cubo[53].escalar(1, 2, 1);
    cubo[53].draw();

    cubo[54].trasladar(13, 0, 2);
    cubo[54].escalar(1, 2, 1);
    cubo[54].draw();

    cubo[55].trasladar(14, 0, 13);
    cubo[55].escalar(5, 2, 1);
    cubo[55].rotar(90, 0, 1, 0);
    cubo[55].draw();

    cubo[56].trasladar(0, 0, 12);
    cubo[56].escalar(15, 2, 1);
    cubo[56].draw();

    cubo[57].trasladar(-16, 0, 15);
    cubo[57].escalar(15, 2, 1);
    cubo[57].rotar(90, 0, 1, 0);
    cubo[57].draw();

    cubo[80].trasladar(-16, 0, 0);
    cubo[80].escalar(17, 2, 1);
    cubo[80].rotar(90, 0, 1, 0);
    cubo[80].draw();

    cubo[58].trasladar(-15, 0, 14);
    cubo[58].escalar(15, 2, 1);
    cubo[58].draw();

    cubo[81].trasladar(0, 0, 14);
    cubo[81].escalar(17, 2, 1);
    cubo[81].draw();

    cubo[59].trasladar(16, 0, 15);
    cubo[59].escalar(15, 2, 1);
    cubo[59].rotar(90, 0, 1, 0);
    cubo[59].draw();

    cubo[82].trasladar(16, 0, 0);
    cubo[82].escalar(17, 2, 1);
    cubo[82].rotar(90, 0, 1, 0);
    cubo[82].draw();

    cubo[60].trasladar(0, 0, -17);
    cubo[60].escalar(17, 2, 1);
    cubo[60].draw();

    cubo[83].trasladar(-15, 0, -17);
    cubo[83].escalar(15, 2, 1);
    cubo[83].draw();

    glPopMatrix();
}

void Laberinto::setXZ(){

    XZ[0] = cubo[1];
   // XZ[1] = cubo[61];
    XZ[1] = cubo[5];
    XZ[2] = cubo[62];
    XZ[3] = cubo[4];
    XZ[4] = cubo[13];
    XZ[5] = cubo[70];
    XZ[6] = cubo[23];
    XZ[7] = cubo[72];
    XZ[8] = cubo[29];
    XZ[9] = cubo[74];
    XZ[10] = cubo[44];
    XZ[11] = cubo[76];
    XZ[12] = cubo[54];
    XZ[13] = cubo[79];
    XZ[14] = cubo[55];
    XZ[15] = cubo[56];
    XZ[16] = cubo[59];
    XZ[17] = cubo[81];

  /*  for(int i =0; i <19; i++){
        XZ[i].calcularCoord();
    }*/
}

void Laberinto::setmenosXmenosZ(){

    menosXmenosZ[0] = cubo[7];
    menosXmenosZ[1] = cubo[63];
    menosXmenosZ[2] = cubo[10];
    menosXmenosZ[3] = cubo[9];
    menosXmenosZ[4] = cubo[17];
    menosXmenosZ[5] = cubo[11];
    menosXmenosZ[6] = cubo[19];
    menosXmenosZ[7] = cubo[20];
    menosXmenosZ[8] = cubo[21];
    menosXmenosZ[9] = cubo[71];
    menosXmenosZ[10] = cubo[31];
    menosXmenosZ[11] = cubo[30];
    menosXmenosZ[12] = cubo[33];
    menosXmenosZ[13] = cubo[39];
    menosXmenosZ[14] = cubo[40];
    menosXmenosZ[15] = cubo[41];
    menosXmenosZ[16] = cubo[49];
    menosXmenosZ[17] = cubo[77];
    menosXmenosZ[18] = cubo[48];
    menosXmenosZ[19] = cubo[78];
    menosXmenosZ[20] = cubo[80];
    menosXmenosZ[21] = cubo[83];
}

void Laberinto::setmenosXZ(){

    menosXZ[0] = cubo[0];
    menosXZ[1] = cubo[6];
    menosXZ[2] = cubo[4];
    menosXZ[3] = cubo[3];
    menosXZ[4] = cubo[10];
    menosXZ[5] = cubo[15];
    menosXZ[6] = cubo[18];
    menosXZ[7] = cubo[24];
    menosXZ[8] = cubo[25];
    menosXZ[9] = cubo[26];
    menosXZ[10] = cubo[28];
    menosXZ[11] = cubo[22];
    menosXZ[12] = cubo[30];
    menosXZ[13] = cubo[37];
    menosXZ[14] = cubo[38];
    menosXZ[15] = cubo[45];
    menosXZ[16] = cubo[49];
    menosXZ[17] = cubo[46];
    menosXZ[18] = cubo[47];
    menosXZ[19] = cubo[58];
    menosXZ[20] = cubo[57];
}

void Laberinto::setXmenosZ(){

    XmenosZ[0] = cubo[2];
    XmenosZ[1] = cubo[64];
    XmenosZ[2] = cubo[8];
    XmenosZ[3] = cubo[65];
    XmenosZ[4] = cubo[67];
    XmenosZ[5] = cubo[12];
    XmenosZ[6] = cubo[22];
    XmenosZ[7] = cubo[68];
    XmenosZ[8] = cubo[69];
    XmenosZ[9] = cubo[73];
    XmenosZ[10] = cubo[36];
    XmenosZ[11] = cubo[35];
    XmenosZ[12] = cubo[34];
    XmenosZ[13] = cubo[43];
    XmenosZ[14] = cubo[42];
    XmenosZ[15] = cubo[75];
    XmenosZ[16] = cubo[53];
    XmenosZ[17] = cubo[52];
    XmenosZ[18] = cubo[51];
    XmenosZ[19] = cubo[50];
    XmenosZ[20] = cubo[82];
    XmenosZ[21] = cubo[60];
}

bool Laberinto::verificarCoordenadas(float x, float z){

    //printf("Recibe: %f, %f", x, z);
    if((x > 0 && z > 0) || (x == 0 && z > 0)){
            //printf("\n X : %f Z: %f \n", x, z);
            setXZ();
        return c.verificarColision( x, z , tamXZ, XZ);
    }if((x < 0 && z > 0) || (x < 0 && z == 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            setmenosXZ();
        return c.verificarColision( x, z, tammenosXZ, menosXZ );
    }if((x > 0 && z < 0) || (x > 0 && z == 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            setXmenosZ();
         return c.verificarColision( x, z, tamXmenosZ, XmenosZ );
    }if((x < 0 && z < 0) || (x == 0 && z < 0)){
            //printf("\n X : %f Z: %f \n",x,z);
            setmenosXmenosZ();
        return c.verificarColision( x, z, tammenosXmenosZ, menosXmenosZ );
    }
}
