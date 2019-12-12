/*GLfloat	camX = 0.0;
GLfloat	camY = 8.0;
GLfloat	camZ = -40.0;
GLfloat	camYaw = 180.0;
GLfloat	camPitch = 0.0;

int	isInMouseDrag = false;
int	mouseIsInverted = true;
int	viewPortCenterX = -1;
int	viewPortCenterY = -1;
int	oldCursorID = 0;
int	oldCursorX = 0;
int	oldCursorY = 0;


void enterMouseDrag( int x, int y )
{
 if( isInMouseDrag )
	return;
 isInMouseDrag = true;
 if( viewPortCenterX < 0 )
	{
	viewPortCenterX = glutGet( GLUT_WINDOW_WIDTH ) / 2;
	viewPortCenterY = glutGet( GLUT_WINDOW_HEIGHT ) / 2;
	}
 oldCursorID = glutGet( GLUT_WINDOW_CURSOR );
 oldCursorX = x;
 oldCursorY = y;
 glutSetCursor( GLUT_CURSOR_NONE );
 glutWarpPointer( viewPortCenterX, viewPortCenterY );
}

void exitMouseDrag( int x, int y )
{
 if( !isInMouseDrag )
	return;
 isInMouseDrag = false;
 glutSetCursor( oldCursorID );
 glutWarpPointer( oldCursorX, oldCursorY );
}

void clampCamera()
{
 if( camPitch > 90.0 )
	camPitch = 90.0;
 else if( camPitch < -90.0 )
	camPitch = -90.0;
 while( camYaw < 0.0 )
	camYaw += 360.0;
 while( camYaw >= 360.0 )
	camYaw -= 360.0;
}

void dollyCamera( GLfloat dollyBy, GLfloat dollyAngle )
{
 GLfloat actualAngleInRadians;
 actualAngleInRadians = ( ( camYaw + dollyAngle ) * M_PI / 180.0 );
 camX -= sin( actualAngleInRadians ) * dollyBy * DEF_dollyStepSize;
 camZ -= cos( actualAngleInRadians ) * dollyBy * DEF_dollyStepSize;
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
// Movimiento hacia adelante
	case 'w':
	case 'W':
		dollyCamera( DEF_dollyStepSize, 0.0 );
		break;

// Movimiento hacia atras
	case 's':
	case 'S':
		dollyCamera( DEF_dollyStepSize, 180.0 );
		break;

// Strafe hacia la izquierda
	case 'a':
	case 'A':
		dollyCamera( DEF_dollyStepSize, 90.0 );
		break;

// Strafe derecha
	case 'd':
	case 'D':
		dollyCamera( DEF_dollyStepSize, 270.0 );
		break;


// Toggle 'inverted' mouse.
	case 'i':
	case 'I':
		mouseIsInverted = !mouseIsInverted;
		break;

//Esc salir
	case 27:				
		exitMouseDrag( 0, 0 );
		exit( 0 );
		break;
  }
}

void specialFunc( int key, int x, int y )
{
	switch( key )
	{
	//giro  a la izquierda
	case GLUT_KEY_LEFT:
		camYaw += 1.0;
		clampCamera();
		break;

	// giro a la derecha.
	case GLUT_KEY_RIGHT:
		camYaw -= 1.0;
		clampCamera();
		break;

	// mirar hacia arriba.
	case GLUT_KEY_UP:
		camPitch += 1.0;
		clampCamera();
		break;

	// mirar hacia abajo
	case GLUT_KEY_DOWN:
		camPitch -= 1.0;
		clampCamera();
		break;
	}
}

void mouseFunc( int button, int state, int x, int y )
{
 if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
	if( !isInMouseDrag )
		enterMouseDrag( x, y );
	else
		exitMouseDrag( x, y );
	}
}

void allMotionFunc( int x, int y )
{
 int deltaX, deltaY;

 if( !isInMouseDrag )
	return;
 deltaX = x - viewPortCenterX;
 deltaY = y - viewPortCenterY;
 if( deltaX == 0 && deltaY == 0 )
	return;
 glutWarpPointer( viewPortCenterX, viewPortCenterY );
 camYaw -= DEF_angleSensitivity * deltaX;
 camPitch -= DEF_angleSensitivity * deltaY * ( mouseIsInverted ? -1.0 : 1.0 );
 clampCamera();
 glutPostRedisplay();
}

void reshape(int w, int h)
{
 if (!h)
	return;
 glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 viewPortCenterX = w / 2;
 viewPortCenterY = h / 2;
}


void display(void)
{
 int a, b, c;
 int i, j, k;
 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glPushMatrix();
 
 glRotatef( -camPitch, 1.0, 0.0, 0.0 );
 glRotatef( -camYaw, 0.0, 1.0, 0.0 );
 glTranslatef( -camX, -camY, -camZ );

 glBegin(GL_TRIANGLES);
 for (j=0; j<nObjetos; j++)
	{
	for (i=0; i<object[j].nFaces; i++)
		{
		const Face& face = object[j].pFaces[i];
		k=face.material;
		glMaterialfv(GL_FRONT, GL_AMBIENT, pMaterial[k].ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pMaterial[k].diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, pMaterial[k].specular);
		glMaterialf(GL_FRONT, GL_SHININESS, pMaterial[k].shininess);
		a=face.vertexIndices[0];
		b=face.vertexIndices[1];
		c=face.vertexIndices[2];
		glNormal3f(face.faceNormal.x, face.faceNormal.y, face.faceNormal.z); 
		glVertex3f(object[j].pVertices[a].x, object[j].pVertices[a].y, object[j].pVertices[a].z);
		glVertex3f(object[j].pVertices[b].x, object[j].pVertices[b].y, object[j].pVertices[b].z);
		glVertex3f(object[j].pVertices[c].x, object[j].pVertices[c].y, object[j].pVertices[c].z);
		}
	}
 glEnd();
 glPopMatrix();
 glFlush();
 glutSwapBuffers();
}

void init(void)
{
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glShadeModel(GL_SMOOTH);
 glCullFace(GL_BACK);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);

 glLightfv(GL_LIGHT0, GL_POSITION, LightPos0);     
 glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb0);         
 glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif0);        
 glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpc0); 
 glEnable(GL_LIGHT0); 
 glEnable(GL_LIGHTING);
 CargarModelo("quake.dat");
 ReadMaterial("material.mat");
 CalcularNormales();
 enterMouseDrag( 0, 0 );
}

void idle(void)
{
 glutPostRedisplay();
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitWindowSize(500, 375);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 glutCreateWindow("Test 3D");
 init();
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutKeyboardFunc(keyboard);
 glutSpecialFunc( specialFunc );
 glutMouseFunc( mouseFunc );
 glutMotionFunc( allMotionFunc );
 glutPassiveMotionFunc( allMotionFunc );
 glutIdleFunc(idle);
 glutMainLoop();
 killObject();
 return 0;
}*/
#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

// actual vector representing the camera's direction
float lx=0.0f, lz=-1.0f, ly = 0.0f;
// XZ position of the camera
float x=0.0f, z=5.0f, y = 1.0f;

// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red=1.0f, blue=1.0f, green=1.0f;

// angle for rotating triangle
float angle = 0.0f;

//int dummy = 5;

void drawSnowMan(){

    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw Body
    glTranslatef(0.0f ,0.75f, 0.0f);
    glutSolidSphere(0.75f,20,20);

    // Draw Head
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f,20,20);

    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f,10,10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();

    // Draw Nose
    glColor3f(1.0f, 0.5f , 0.5f);
    glRotatef(0.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.08f,0.5f,10,2);
}

void changeSize(int w, int h){

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

// Clear Color and Depth Buffers

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f);

    // Draw ground
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    // Draw 36 SnowMen
    for(int i = -3; i < 3; i++)
    for(int j=-3; j < 3; j++) {
        glPushMatrix();
        glTranslatef(i*10.0,0,j * 10.0);
        drawSnowMan();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y){

    if (key == 27)
        exit(0);
}

void processSpecialKeys(int key, int xx, int yy){

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_RIGHT :
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
            case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
        break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
        break;
        case '119':
            ly += 1;
            break;
        case '115':
            y += 1;
            break;
        }
}

int main(int argc, char **argv){

// init GLUT and create window

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Lighthouse3D - GLUT Tutorial");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
