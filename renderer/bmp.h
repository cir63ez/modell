#pragma once
#include "lib.h"

#define BYTES_PER_PIXEL 3
#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define MAX_IMAGE_HEIGHT 400
#define MAX_IMAGE_WIDTH 400

// http://www.fastgraph.com/help/bmp_header_format.html
// TODO: Refaire en regardant ce qu'il y a dans bmp-internet.c, soit:

void BMPSetColor(unsigned char image[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH][BYTES_PER_PIXEL], int x, int y, Rgb color);
void generateBitmapImage(unsigned char *image, int height, int width, char *imageFileName);
unsigned char *createBitmapFileHeader(int height, int width);
unsigned char *createBitmapInfoHeader(int height, int width);