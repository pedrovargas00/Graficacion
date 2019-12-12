#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
//#include "FreeImage.h"
#include "Textura.h"
#include "Objeto.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

FIBITMAP *dib1;
GLuint texturas;
Textura textura;
GLint ancho, alto;
Objeto objeto;

int hazPerspectiva = 1;

GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f;

void reshape(int width , int height){
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(hazPerspectiva)
        gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
    else
        glOrtho(-4, 4, -4, 4, 1, 10);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        ancho = width;
        alto = height;
}

void obj(char *archivo){


}

void drawCube(void){
//1
    glColor3f(1.0f, 0.0f, 0.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    dib1 = textura.loadImage("C:/Users/Pedro/Downloads/dementor.jpg");
    texturas = textura.loadTexture(dib1);
    FreeImage_Unload(dib1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas);
    glBlendFunc(GL_ONE, GL_ONE);

    //glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    //1- derecha
        /*glVertex3f(1, 0, 1);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, 1);
    //2- izquierda
        glVertex3f(0, 1, 1);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
    //3- arriba
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, 1);
    //4- abajo
        glVertex3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
    //5 atras
        glVertex3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);*/
    //6- enfrente
        glTexCoord2d(1, 1);
        glVertex3f(1, 1, 1);
        glTexCoord2d(0, 1);
        glVertex3f(0, 1, 1);
        glTexCoord2d(0, 0);
        glVertex3f(0, 0, 1);
        glTexCoord2d(1, 0);
        glVertex3f(1, 0, 1);
    glEnd();

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    //objeto.draw("C:/Users/Pedro/Desktop/Sandtrooper/Sandtrooper.obj");
    //drawCube();

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);


    glTranslatef(3.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireSphere(0.5f, 8, 8);

    glFlush();
    glutSwapBuffers();

    anguloCuboX += 0.01f;
    anguloCuboY += 0.01f;
    anguloEsfera += 0.01f;
}

void init(){

    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
    /*AllocConsole();
    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );
*/
    /*objeto.load("C:/Users/Pedro/Desktop/Sandtrooper/Sandtrooper.obj");

    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);*/
}

void idle(){
    display();
}

static void keyboard(unsigned char key, int x, int y){
    switch(key){

    case 'p':
    case 'P':
        hazPerspectiva = 1;
        reshape(ancho, alto);
        break;
    case 'o':
    case 'O':
        hazPerspectiva = 0;
        reshape(ancho, alto);
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
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Cubo 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

/*GLfloat	xrot=0.0;
GLfloat yrot=0.0;
GLfloat zrot=0.0;

GLuint texture[1];

//parametros de la fuente de luz
GLfloat LightAmbient[]={ 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]={ 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]={ 1.0f, 1.0f, 1.0f, 0.0f };

AUX_RGBImageRec *LoadBMP(char *Filename){	// Loads A Bitmap Image{

    FILE *File=NULL;	// File Handle
    if (!Filename){	// Make Sure A Filename Was Given{
        return NULL;	// If Not Return NULL
    }
    File=fopen(Filename,"r");	// Check To See If The File Exists
    if (File){	// Does The File Exist?{
        fclose(File);	// Close The Handle
        return auxDIBImageLoad(Filename);	// Load The Bitmap And Return A Pointer
    }
    return NULL;	// If Load Failed Return NULL
}

int LoadGLTextures(){	// Load Bitmaps And Convert To Textures{

    int Status=FALSE;	// Status Indicator

    AUX_RGBImageRec *TextureImage[1];	// Create Storage Space For The Texture
    memset(TextureImage,0,sizeof(void *)*1); // Set The Pointer To NULL
    // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
    if (TextureImage[0]=LoadBMP("imagen.bmp")){
        Status=TRUE;	// Set The Status To TRUE
        glGenTextures(1, &texture[0]);	// Create The Texture
        // Typical Texture Generation Using Data From The Bitmap
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        TextureImage[0]->sizeX,
        TextureImage[0]->sizeY,
        0, GL_RGB, GL_UNSIGNED_BYTE,
        TextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }
    if (TextureImage[0]){	// If Texture Exists
        if (TextureImage[0]->data){	// If Texture Image Exists
            free(TextureImage[0]->data);	// Free The Texture Image Memory
        }

        free(TextureImage[0]);	// Free The Image Structure
    }
    return Status;	// Return The Status
}

void init(void){
    //Carga la textura
    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    //posicion de la fuente de luz
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
    //activa la luz
    glEnable(GL_LIGHT1);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-4.5f);
    //Rota el cubo
    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);
    glRotatef(zrot,0.0f,0.0f,1.0f);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    // Frente
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    // parte de Atras
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    // Arriba
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    // Abajo
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    // lado Derecho
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    // Lado Izquierdo
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    glFlush ();
    glutSwapBuffers();
}

void reshape (int width, int height){

    if (height == 0){
        height = 1;
    }
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 27:
            exit(0);
            break;
    }
}

//Incremento los angulos de rotacion
void Idle(void){
    xrot+=5.0f;
    yrot+=6.0f;
    zrot+=7.0f;
    display();
}

int main(int argc, char** argv){
//Inicializar el estado de GLUT
    glutInit(&argc, argv);

    //Seleccionar el tipo de modo de display Buffer doble y color RGBA
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    //Poner el tamaño y posición de la ventana
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Textura 3D");

    init ();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}*/
