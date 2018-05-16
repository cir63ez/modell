#include "bmp.h"

int main() {
	int height = 200;
    int width = 400;
    unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName = "bitmapImage.bmp";

    Rgb white;
    white.red = 255;
    white.green = 255;
    white.blue = 255;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            BMPSetColor(image, i, j, white);
        }
    }

    generateBitmapImage((unsigned char *)image, height, width, imageFileName);

	return 0;
}