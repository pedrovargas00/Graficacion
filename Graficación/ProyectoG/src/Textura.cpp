#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include <FreeImage.h>
#include <Textura.h>
#include <stdio.h>
#include <stdlib.h>

Textura::Textura(){}
Textura::~Textura(){}

FIBITMAP* Textura::loadImage(const char *filename){

    FIBITMAP *dib1 = NULL;
    FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(filename);

    dib1 = FreeImage_Load(fif, filename, JPEG_DEFAULT);
    if (!dib1){
       printf("No existe imagen");
       exit(0);
    }
    return dib1;
}

GLuint Textura::loadTexture (FIBITMAP  * dib1){

    GLuint tex_id = 0;
    int x, y;
    int height, width;

    RGBQUAD rgbquad;

    FREE_IMAGE_TYPE type;
    BITMAPINFOHEADER *header;
    type = FreeImage_GetImageType(dib1);
    height = FreeImage_GetHeight(dib1);
    width = FreeImage_GetWidth(dib1);

    header = FreeImage_GetInfoHeader(dib1);
    int scanLineWidh = ((3*width)%4 == 0) ? 3*width : ((3*width)/4)*4+4;
    unsigned char * texels= (GLubyte*)calloc(height*scanLineWidh, sizeof(GLubyte));
    for (x=0 ; x<width ; x++)
        for (y=0 ; y<height; y++){
            FreeImage_GetPixelColor(dib1,x,y,&rgbquad);
              texels[(y*scanLineWidh+3*x)]=((GLubyte*)&rgbquad)[2];
              texels[(y*scanLineWidh+3*x)+1]=((GLubyte*)&rgbquad)[1];
              texels[(y*scanLineWidh+3*x)+2]=((GLubyte*)&rgbquad)[0];
        }

    glGenTextures (1, &tex_id);
    glBindTexture (GL_TEXTURE_2D, tex_id);

    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB,
        width, height, 0, GL_RGB,
        GL_UNSIGNED_BYTE, texels);
    free(texels);
    return tex_id;
}
