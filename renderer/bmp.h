#include "lib.h"

/**
 * typedef struct Rgb_ {
    double red;
    double green;
    double blue;
} Rgb;
 */

typedef struct BMPFile_ {
	int height;
	int width;
	Rgb* pixels;
} BMPFile;

BMPFile *newBMP(int width, int height);
void BMPSetColor(BMPFile *image, int x, int y, Rgb color);
void tempPrint(BMPFile *image);