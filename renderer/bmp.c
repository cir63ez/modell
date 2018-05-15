#include "bmp.h"

BMPFile *newBMP(int width, int height) {
	BMPFile *image;
	Rgb *pixelsGrid;

	image = (BMPFile *) malloc(sizeof(BMPFile));
	pixelsGrid = (Rgb *) malloc(sizeof(Rgb) * width * height);
	
	image->width = width;
	image->height = height;
	image->pixels = pixelsGrid;

	return image;
}

// 0------x------>
// |      |      
// y------■      
// |
// V             
void BMPSetColor(BMPFile *image, int x, int y, Rgb color) {
	int index;
	Rgb* pixelsGrid;

	index = y * image->width + x;
	pixelsGrid = image->pixels;

	pixelsGrid[index] = color;
}

void tempPrint(BMPFile *image) {
	int index;
	Rgb* pixelsGrid;

	pixelsGrid = image->pixels;

	for(int i = 0; i < image->height; i++) {
		for(int j = 0; j < image->width; j++) {
			index = i*image->width + j;
			printf("[%3d]", pixelsGrid[index].red);
		}
		printf("\n");
	}

	printf("\n");

	for(int i = 0; i < image->height; i++) {
		for(int j = 0; j < image->width; j++) {
			index = i*image->width + j;
			printf("[%3d]", pixelsGrid[index].green);
		}
		printf("\n");
	}

	printf("\n");

	for(int i = 0; i < image->height; i++) {
		for(int j = 0; j < image->width; j++) {
			index = i*image->width + j;
			printf("[%3d]", pixelsGrid[index].blue);
		}
		printf("\n");
	}
}