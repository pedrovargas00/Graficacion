#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Agente.h"
#include <stdlib.h>
#include <stdio.h>

Agente agente;
int opcion;
float Theta = 0;

int WIDTH = 500;
int HEIGHT = 500;

float FOVY = 30.0;
float ZNEAR = 0.05;
float ZFAR = 200.0;

float EYE_X = 20.0;
float EYE_Y = 15.5;
float EYE_Z = 55.0;
float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = 0;

float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;

float X_MIN = -20;
float Y_MIN = -20;
float Z_MIN = -20;
float X_MAX = 20;
float Y_MAX = 20;
float Z_MAX = 20;


void idle(void){
    Sleep(20);
    glutPostRedisplay();
}

void Reshape(int width , int height){
    glViewport(0, 0, width, height);
}

void cuboMenosX(){

    glPushMatrix();
    glTranslatef(-15, 0.0, 0.0);
    glColor3f(1.0, 1.0 , 1.0);
    agente.cubo();
    glPopMatrix();
}

void cuboX(){

    glPushMatrix();
    glTranslatef(15, 0.0, 0.0);
    glColor3f(1.0, 1.0 , 1.0);
    agente.cubo();
    glPopMatrix();
}

void cuboMenosZ(){

    glPushMatrix();
    glTranslatef(0.0, 0.0, -20);
    glColor3f(1.0, 1.0 , 1.0);
    agente.cubo();
    glPopMatrix();
}

void cuboZ(){

    glPushMatrix();
    glTranslatef(0.0, 0.0, 20);
    glColor3f(1.0, 1.0 , 1.0);
    agente.cubo();
    glPopMatrix();
}

void drawAxis(){

    glLineWidth(0.01);
        glBegin(GL_LINES);
        glVertex3f(X_MIN, 0, 0);
        glVertex3f(X_MAX, 0, 0);
        glVertex3f(0, Y_MIN, 0);
        glVertex3f(0, Y_MAX, 0);
        glVertex3f(0, 0, Z_MIN);
        glVertex3f(0, 0, Z_MAX);
    glEnd();

}

static void keys(unsigned char key, int x, int y){

    switch(key){
        case GLUT_KEY_UP:
            opcion = 1;
            break;
        case GLUT_KEY_DOWN:
            opcion = 2;
            break;
        case GLUT_KEY_RIGHT:
            opcion = 3;
            break;
        case GLUT_KEY_LEFT:
            opcion = 4;
            break;
    }
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawAxis();
    cuboMenosX();
    cuboX();
    cuboMenosZ();
    cuboZ();
    switch(opcion){

        case 1:
            glPushMatrix();
            glTranslated(rand()%21, 0, 0);
            agente.cubo();
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
            glTranslated((-1)*(rand()%21), 0, 0);
            agente.cubo();
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
            glTranslated(0, 0, rand()%21);
            agente.cubo();
            glPopMatrix();
            break;
        case 4:
            glPushMatrix();
            glTranslated(0, 0, (-1)*(rand()%21));
            agente.cubo();
            glPopMatrix();
            break;
    }
    //agente.cubo();
    glFlush();
    glutSwapBuffers();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGHT, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z , UP_X , UP_Y, UP_Z);
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Parcial dos");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(keys);
    glutMainLoop();
    return 0;
}
