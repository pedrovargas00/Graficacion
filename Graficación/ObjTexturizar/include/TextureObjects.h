#ifndef TEXTUREOBJECTS_H
#define TEXTUREOBJECTS_H


class TextureObjects
{
    const bool TEXTURE_DEBUG = true;			//set debug so we get feedback about what is going on

#pragma comment(lib, "glaux.lib")
#include <GL\glaux.h>

#pragma comment(lib, "jpeg.lib")
#include "jpeglib.h"


//Define a new structure to hold the image information
typedef struct _ImageDataRec {
	int rowSpan;
	int sizeX;
	int sizeY;
	unsigned char *data;
} ImageDataRec;


class CTextures
{
	public:

		// Typical constructor
		CTextures();

		// This will clean up memory and close the sound system
		~CTextures();

		// This will load the texture from the file and put it into the passed texture
		bool LoadTexture(char *mFileName, UINT &mTexture);

	private:
		// This checks to make sure the file exists
		bool FileExist(char *mFileName);

};

#endif
