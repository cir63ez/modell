#pragma once
#include "lib.h"

#define BYTES_PER_PIXEL 3
#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define MAX_IMAGE_HEIGHT 400
#define MAX_IMAGE_WIDTH 400

typedef struct BMP_ {
    int height;
    int width;
    Rgb *pixels;
} BMP;

// Generates an empty BMP image
BMP *newBMP(int height, int width);

// Sets the pixel of an image
void BMPSetColor(BMP *image, int x, int y, Rgb color);

// Applies Box Blur to an image
void blurBmpImage (BMP *image, double blurValue);

// Exports a BMP Image to a BMP File
void exportBMPImageToFile(BMP *image, char *filename);

// Generates the Bitmap File Header
unsigned char *createBitmapFileHeader(int height, int width);

// Generates the Bitmap Info Header
unsigned char *createBitmapInfoHeader(int height, int width);
