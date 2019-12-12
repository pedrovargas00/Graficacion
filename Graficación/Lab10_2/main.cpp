#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

GLint ancho, alto;
int hazPerspectiva = 1;

GLfloat anguloLuna = 0.0f;
GLfloat anguloSol = 0.0f;
GLfloat anguloTierra = 0.0f;
GLfloat anguloMercurio = 0.0f;
GLfloat anguloVenus = 0.0f;
GLfloat anguloMarte = 0.0f;
GLfloat anguloJupiter = 0.0f;
GLfloat anguloSaturno = 0.0f;
GLfloat anguloUrano = 0.0f;
GLfloat anguloNeptuno = 0.0f;

float EYE_X = 0.0;
float EYE_Y = 0.0;
float EYE_Z = 5.0;

float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = 0;

float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;

void reshape(int width , int height){

    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(hazPerspectiva)
        gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
    else
        glOrtho(-6, 6, -6, 6, 1, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z, UP_X, UP_Y, UP_Z);
    ancho = width;
    alto = height;
}

void anillo(){

    float x, z, r = 2;
    glPushMatrix();
    glRotatef(anguloSaturno, 0, 1, 0);
    glTranslatef(5, 0.0, 0.0);
    glColor3f(1.0,  1.0 , 1.0);
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        for(float i = 0; i < 10; i += 0.01){
            r -= 0.1;
            x = r * cos(i);
            z = r * sin(i);
            glVertex3f(x, 0, z);
        }
    glEnd();
    glPopMatrix();
}

void sol(){

    glPushMatrix();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloSol, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0,  1.0 , 0.0);
    glutWireSphere(1.0f, 20, 20);
    glPopMatrix();
}


void lunaJ(float a, float x, float y){

    glPushMatrix();
    glRotatef(anguloJupiter - a, 0, 1, 0);
    glTranslatef(0.3 + x, 0.0 + y, 0.0);
    glColor3f(1.0,  1.0 , 1.0);
    glutWireSphere(0.03f, 10, 10);
    glPopMatrix();
}

void luna(){

    glPushMatrix();
    glRotatef(anguloLuna, 0, 1, 0);
    glTranslatef(0.4, 0.0, 0.0);
    glColor3f(1.0,  1.0 , 1.0);
    glutWireSphere(0.05f, 10, 10);
    glPopMatrix();
}

void tierra(){

    glPushMatrix();
    glRotatef(anguloTierra, 0, 1, 0);
    glTranslatef(2.5, 0.0, 0.0);
    glColor3f(0.0,  0.0 , 1.0);
    glutWireSphere(0.3f, 10, 10);
    luna();
    glPopMatrix();
}

void mercurio(){

    glPushMatrix();
    glRotatef(anguloMercurio, 0, 1, 0);
    glTranslatef(1.2, 0.0, 0.0);
    glColor3f(0.3, 0.4, 0.3);
    glutWireSphere(0.2f, 10, 10);
    glPopMatrix();
}

void venus(){

    glPushMatrix();
    glRotatef(anguloVenus, 0, 1, 0);
    glTranslatef(1.6, 0.0, 0.0);
    glColor3f(1.0, 0.5, 0.0);
    glutWireSphere(0.2f, 10, 10);
    glPopMatrix();
}

void marte(){

    glPushMatrix();
    glRotatef(anguloMarte, 0, 1, 0);
    glTranslatef(3.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutWireSphere(0.2f, 10, 10);
    glPopMatrix();
}

void jupiter(){

    glPushMatrix();
    glRotatef(anguloJupiter, 0, 1, 0);
    glTranslatef(4, 0.0, 0.0);
    glColor3f(0.7, 0.4, 0.1);
    glutWireSphere(0.8f, 20, 20);
    lunaJ(0, 0, 0);
    lunaJ(0.1, -0.8, 0.2);
    lunaJ(0.3, 0.2, -0.1);
    lunaJ(0.0, -1, -0.3);
    glPopMatrix();
}

void saturno(){

    glPushMatrix();
    glRotatef(anguloSaturno, 0, 1, 0);
    glTranslatef(5, 0.0, 0.0);
    glColor3f(0.4, 0.4, 0.1);
    glutWireSphere(0.6f, 15, 15);
    anillo();
    glPopMatrix();
}

void urano(){

    glPushMatrix();
    glRotatef(anguloUrano, 0, 1, 0);
    glTranslatef(5.3, 0.0, 0.0);
    glColor3f(0.0, 0.5, 0.7);
    glutWireSphere(0.3f, 10, 10);
    luna();
    glPopMatrix();
}

void neptuno(){

    glPushMatrix();
    glRotatef(anguloNeptuno, 0, 1, 0);
    glTranslatef(5.6, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.5);
    glutWireSphere(0.2f, 10, 10);
    luna();
    glPopMatrix();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    sol();
    mercurio();
    venus();
    tierra();
    marte();
    jupiter();
    saturno();
    urano();
    neptuno();
    glFlush();
    glutSwapBuffers();

    anguloSol += 0.01f;
    anguloTierra += 0.02f;
    anguloLuna += 0.06f;
    anguloMercurio += 0.09f;
    anguloVenus += 0.05f;
    anguloMarte += 0.01f;
    anguloJupiter += 0.009f;
    anguloSaturno += 0.007f;
    anguloUrano += 0.004f;
    anguloNeptuno += 0.002f;
}

void init(){

    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
}

void idle(){
    display();
}

static void keyboard(unsigned char key, int x, int y){
    switch(key){

    case 'p':
    case 'P':
        hazPerspectiva = 1;
        reshape(ancho,alto);
        break;
    case 'o':
    case 'O':
        hazPerspectiva = 0;
        reshape(ancho,alto);
        break;
    case 'e':
    case 'E':
        exit(0);
        break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sol Tierra Luna");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
