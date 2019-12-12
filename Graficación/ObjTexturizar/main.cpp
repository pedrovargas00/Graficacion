#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
// Loading3DSFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ThreeMaxLoader.h"
#include <GL/glut.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glut32.lib")

int screen_width=600;
int screen_height=600;

float rotation_x=0; float rotation_x_increment=0.06f;
float rotation_y=0; float rotation_y_increment=0.1f;
float rotation_z=0; float rotation_z_increment=0.03f;

obj_type object;
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // This clear the background color to black
    glShadeModel(GL_SMOOTH); // Type of shading for the polygons

	 // Projection transformation
    glMatrixMode(GL_PROJECTION); // Specifies which matrix stack is the target for matrix operations
    glLoadIdentity(); // We initialize the projection matrix as identity
    //glOrtho(-100.0f,100.0f,-100.0f,100.0f,100.0f,-100.0f);
	gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,10.0f,10000.0f);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST); // We enable the depth test (also called z buffer)
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	//Convert string to char

	CThreeMaxLoader::Load3DS(&object,"chesspawn.3ds");

}
void render()
{
	int l_index;

	glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // Modeling transformation
	glLoadIdentity();

	glTranslatef(0.0,0.0,-500.0);
	glColor3d(1,1,0);
    glRotatef(rotation_x,1.0,0.0,0.0); // Rotations of the object (the model matrix is multiplied by the rotation matrices)
    glRotatef(rotation_y,0.0,1.0,0.0);
    glRotatef(rotation_z,0.0,0.0,1.0);

		// TODO: Add your message handler code here
	rotation_x = rotation_x + rotation_x_increment;
    rotation_y = rotation_y + rotation_y_increment;
    rotation_z = rotation_z + rotation_z_increment;

    if (rotation_x > 359) rotation_x = 0;
    if (rotation_y > 359) rotation_y = 0;
    if (rotation_z > 359) rotation_z = 0;


	glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
    for (l_index=0;l_index<object.polygons_qty;l_index++)
    {
        //----------------- FIRST VERTEX -----------------
        // Coordinates of the first vertex
        glVertex3f( object.vertex[ object.polygon[l_index].a ].x,
                    object.vertex[ object.polygon[l_index].a ].y,
                    object.vertex[ object.polygon[l_index].a ].z); //Vertex definition

        //----------------- SECOND VERTEX -----------------
        // Coordinates of the second vertex
		//float x= object.vertex[ object.polygon[l_index].b ].x;

        glVertex3f( object.vertex[ object.polygon[l_index].b ].x,
                    object.vertex[ object.polygon[l_index].b ].y,
                    object.vertex[ object.polygon[l_index].b ].z);

        //----------------- THIRD VERTEX -----------------
        // Coordinates of the Third vertex
        glVertex3f( object.vertex[ object.polygon[l_index].c ].x,
                    object.vertex[ object.polygon[l_index].c ].y,
                    object.vertex[ object.polygon[l_index].c ].z);
    }
    glEnd();
	glutSwapBuffers();
}
void reshape(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,10.0f,10000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	//window settings
	glutInitWindowPosition(100,100);
	glutInitWindowSize(screen_width,screen_height);
	glutCreateWindow("Loading 3DS file");

	init();

	glutDisplayFunc(render);
	glutIdleFunc(render);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}
