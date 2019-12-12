#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Cubo.h"
#include "Laberinto.h"
#include "Escenario.h"

Cubo cubo;
Laberinto laberinto;
Escenario escenario;
float Theta = 0;
double angulo = 0;
float coordX, coordZ;
int WIDTH = 500;
int HEIGHT = 500;
//Es el grado de visualización con respecto al observador
float FOVY = 45.0;
//Es qué tan cerca puedes ver
float ZNEAR = 0.1;
//Qué tan lejos puedes ver.
float ZFAR = 200.0;
//float EYE_X = 15.5;float EYE_Y = 0.4;

//float EYE_X = -0.5;
//float EYE_Y = 0.4;
//float EYE_Z = 0.5;

float EYE_X = 0.5;
float EYE_Y = 0.4;
float EYE_Z = -0.5;

float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = -2;
/*float EYE_X = 5.5;
float EYE_Y = 70.5;
float EYE_Z = 2.5;

float CENTER_X = 0.1;
float CENTER_Y = -70.0;
float CENTER_Z = 0.1;
*/
float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;

float X_MIN = -20;
float Y_MIN = -20;
float Z_MIN = -100;
float X_MAX = 20;
float Y_MAX = 20;
float Z_MAX = 25;

void idle(void){
    Sleep(20);
    glutPostRedisplay();
}

void Reshape(int width , int height){

    glViewport(0, 0, width, height);
    gluLookAt(EYE_X, EYE_Y, EYE_Z, EYE_X+CENTER_X, EYE_Y+CENTER_Y, EYE_Z+CENTER_Z , UP_X , UP_Y, UP_Z);
}

void drawAxis(){

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(0.01);
        glBegin(GL_LINES);
        glVertex3f(X_MIN, 0.1, 0);
        glVertex3f(X_MAX, 0.1, 0);
        glVertex3f(0, Y_MIN, 0);
        glVertex3f(0, Y_MAX, 0);
        glVertex3f(0, 0.1, Z_MIN);
        glVertex3f(0, 0.1, Z_MAX);

    glEnd();
}

void keys(int key, int x, int y){

    float fraction = 0.2f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angulo -= 0.1f;
            CENTER_X = sin(angulo);
            CENTER_Z = -cos(angulo);

        break;
        case GLUT_KEY_RIGHT :
            angulo += 0.1f;
            CENTER_X = sin(angulo);
            CENTER_Z = -cos(angulo);
        break;
        case GLUT_KEY_UP :
            coordX = EYE_X+(CENTER_X * fraction);
            coordZ = EYE_Z+(CENTER_Z * fraction);
            if(escenario.verificarCoordenadas(coordX, coordZ)){
                if(escenario.verificarCoordenadasBono(coordX, coordZ))
                    printf("algo del dementor");
                if(escenario.verificarCoordenadasCopa(coordX, coordZ))
                    printf( "ganó!!!");
                EYE_X += CENTER_X * fraction;
                EYE_Z += CENTER_Z * fraction;

            }
            else
                printf("\nno se puede avanzar, colisiona: x: %f    z: %f",EYE_X+(CENTER_X * fraction), EYE_Z+(CENTER_Z * fraction));
        break;
        case GLUT_KEY_DOWN :

            coordX = EYE_X-(CENTER_X * fraction);
            coordZ = EYE_Z-(CENTER_Z * fraction);
            if(escenario.verificarCoordenadas(coordX, coordZ)){
                if(escenario.verificarCoordenadasBono(coordX, coordZ))
                    printf("algo del dementor");
                if(escenario.verificarCoordenadasCopa(coordX, coordZ))
                    printf( "ganó!!!");
                EYE_X -= CENTER_X * fraction;
                EYE_Z -= CENTER_Z * fraction;

            }
            else
                printf("\nno se puede avanzar, colisiona: x: %f    z: %f",EYE_X-(CENTER_X * fraction), EYE_Z-(CENTER_Z * fraction));
        break;
    }
}


void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Reshape(WIDTH,HEIGHT);
    drawAxis();
    glPushMatrix();
    //cubo.trasladar(EYE_X,0,EYE_Z);
    //cubo.escalar(0.5,1,0.5);
    //cubo.draw();
    glLighti(GL_LIGHT1, GL_AMBIENT, 1.0);
    escenario.setCoordOjos(EYE_X, EYE_Z);
    escenario.draw();
    escenario.verificarCoordenadasDementor();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGHT, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, EYE_X+CENTER_X, EYE_Y+CENTER_Y, EYE_Z+CENTER_Z , UP_X , UP_Y, UP_Z);
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Parcial dos");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(idle);
    glutSpecialFunc(keys);
    glutMainLoop();
    return 0;
}
