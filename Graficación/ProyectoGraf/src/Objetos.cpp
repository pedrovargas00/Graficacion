#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Objetos.h"
#include <stdio.h>

Objetos::Objetos()
{
    //ctor
}

Objetos::~Objetos()
{
    //dtor
}

GLuint Objetos::loadObj(char *fname){

    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    GLuint elephant = glGenLists(1);

    fp = fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(elephant, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
    return elephant;
}
