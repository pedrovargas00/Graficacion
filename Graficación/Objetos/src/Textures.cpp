#include "Textures.h"

Textures::Textures(){
    //ctor
}

Textures::~Textures(){
    //dtor
}

/***** textures.cpp ******/
void Textures::LoadFromFile(char *filename){

     Image = auxDIBImageLoadA( (const char*) filename );
     if (Image==NULL)
         exit(0);
     glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
     glGenTextures(1,&ID);
     glBindTexture( GL_TEXTURE_2D, ID);
     Width = Image->sizeX;
     Height = Image->sizeY;
     gluBuild2DMipmaps(	GL_TEXTURE_2D,3,Image->sizeX,Image->sizeY,GL_RGB,GL_UNSIGNED_BYTE,Image->data);
     delete Image;
}

void Textures::SetActive(){

 glBindTexture( GL_TEXTURE_2D, ID);
}

unsigned int Texture::GetID(){

 return ID;
}
