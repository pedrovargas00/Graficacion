#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// variables dimensiones de la pantalla
int WIDTH = 500;
int HEIGHT = 500;
// variables para definir los valores del GLUT
float FOVY = 60.0;
float ZNEAR = 1.0;
float ZFAR = 100.0;
//variables para definir la posicion del observador
//gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z);
float EYE_X = 0.8;
float EYE_Y = 0.5;
float EYE_Z = 1.0;

float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = 0;
//se manejan como un vector de orientacion
float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;
//variables para dibujar los ejes del sistema
float X_MIN = -20;
float Y_MIN = -20;
float Z_MIN = -100;
float X_MAX = 20;
float Y_MAX = 20;
float Z_MAX = 20;


void drawAxis(){

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex3i(X_MIN,0,0);
    glVertex3i(X_MAX,0,0);
    glVertex3i(0,Y_MIN,0);
    glVertex3i(0,Y_MAX,0);
    glVertex3i(0,0,Z_MIN);
    glVertex3i(0,0,Z_MAX);
    glEnd();

}

void Imprime(){

//triangulo de colores----------------------------------------------------------------------------


    glBegin(GL_TRIANGLES);
    //vertice 1 color rojo
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-4.0,0.0,2.0);
    //vertice 2 color verde
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-3.0,0.0,2.0);
    //vertice 3 color azul
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-3.5,1.0,2.0);
    glEnd();

//triangulo con lineas de colores--------------------------------------------------------------------

    glBegin(GL_LINES);
    //Linea 1 color rojo
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-2.0,0.0,1.0);
    glVertex3f(-1.0,0.0,1.0);
    //Linea 2 color verde
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-1.0,0.0,1.0);
    glVertex3f(-1.5,1.0,1.0);
    //Linea 3 color azul
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-1.5,1.0,1.0);
    glVertex3f(-2.0,0.0,1.0);
    glEnd();

//cuadrado de color solido-------------------------------------------------------------------------------

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    // Color para el cuadrado
    glVertex3f(-0.5,0.5,-1.5);
    // vertice 1 (superior-izquierda)
    glVertex3f(-0.5,-0.5,-0.5);
    // vertice 2 (inferior-izquierda)
    glVertex3f(0.5,-0.5,-0.5);
    // vertice 3 (inferior-derecha)
    glVertex3f(0.5,0.5,-1.5);
    // vertice 4 (superior-derecha)
    glEnd();

//cuadrado de color solido con ocultacion de objetos (oclusión)
//para el efecto de oclusión
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    // Color para el cuadrado
    glVertex3f(1.5,0.5,-2.5);
    // vertice 1 (superior-izquierda)
    glVertex3f(1.5,-0.5,-1.5);
    // vertice 2 (inferior-izquierda)
    glVertex3f(2.5,-0.5,-1.5);
    // vertice 3 (inferior-derecha)
    glVertex3f(2.5,0.5,-2.5);
    // vertice 4 (superior-derecha)
    glEnd();

    glColor3f(3.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    //vertice 1
    glVertex3f(2.0,0.5,-2.0);
    //vertice 2
    glVertex3f(1.3,-0.5,-2.0);
    //vertice 3
    glVertex3f(2.7,-0.5,-2.0);
    glEnd();

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//GL_DEPTH_BUFFER_BIT para el tema de oclusión
    glColor3f(0.50f,1.30f, 1.7f);
    drawAxis();
    Imprime();
    glFlush();
    glutSwapBuffers();

}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(FOVY, (GLfloat)WIDTH/HEIGHT, ZNEAR, ZFAR);
    //como no tenemos el lookAt trasladamos todo el escenario en el eje -z para poder verlo
    //ya que todo está dibujado en la posicion 0 en z
    //glTranslatef(0.0,0.0,-16.0);
    glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z , UP_X , UP_Y, UP_Z);
    //glClearColor(0,0,0,0);
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("DINUJANDO OBJETOS CON OPENGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
