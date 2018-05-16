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

// http://www.fastgraph.com/help/bmp_header_format.html
// TODO: Refaire en regardant ce qu'il y a dans bmp-internet.c, soit:

BMP *newBMP(int height, int width);
void BMPSetColor(BMP *image, int x, int y, Rgb color);
void exportBMPImageToFile(BMP *image, char *filename);
unsigned char *createBitmapFileHeader(int height, int width);
unsigned char *createBitmapInfoHeader(int height, int width);