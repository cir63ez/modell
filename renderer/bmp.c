#include "bmp.h"

/**
 * Generate an empty BMP image
 *
 * @param height: Height of the image (in pixels)
 * @param width: Width of the image (in pixels)
 *
 * @return BMP *: Pointer to the BMP structures containing the image's height,width & pixelsGrid
 */
BMP *newBMP(int height, int width) {
    BMP *image = (BMP *) malloc(sizeof(BMP));
    Rgb *pixelsGrid = (Rgb *) malloc(sizeof(Rgb) * width * height);

    image->height = height;
    image->width = width;
    image->pixels = pixelsGrid;

    return image;
}

/**
 * Set the pixel of an image
 *
 * @param image: Pointer to the BMP element
 * @param x: Position x of the pixel
 * @param y: Position y of the pixel
 *
 * @return void
 *  /------x------->
 *  |      |
 *  |      |
 *  y------* <---point
 *  |
 *  |
 *  v
 */
void BMPSetColor(BMP *image, int x, int y, Rgb color) {
    int height;
    int width;
    Rgb *pixelsGrid;

    height = image->height;
    width = image->width;
    pixelsGrid = image->pixels;

    *(pixelsGrid + y * height + x) = color;
}

/**
 * Export a BMP Image to a BMP File
 *
 * @param image: Pointer to the BMP element
 * @param filename: BMP filename (with extension)
 *
 * @return void
 */

void blurBmpImage (BMP *image, double blurValue){
    Rgb *pixelsGrid;
    int height;
    int width;
    int x;
    int y;

    Rgb averageColorOverTop;
    Rgb averageColorTop;
    Rgb averageColorMiddle;
    Rgb averageColorBottom;
    Rgb averageColorUnderBottom;
    Rgb averageColor;

    height = image->height;
    width = image->width;
    pixelsGrid = image->pixels;

    for (int i = width * 2; i < height * (width - 2); i++){
        averageColorOverTop.red   = pixelsGrid[i - 2 * (width + 1)].red   + pixelsGrid[i - (2 * width + 1)].red   + pixelsGrid[i - 2 * width].red   + pixelsGrid[i - 2 * width + 1].red   + pixelsGrid[i - 2 * width + 2].red;
        averageColorOverTop.green = pixelsGrid[i - 2 * (width + 1)].green + pixelsGrid[i - (2 * width + 1)].green + pixelsGrid[i - 2 * width].green + pixelsGrid[i - 2 * width + 1].green + pixelsGrid[i - 2 * width + 2].green;
        averageColorOverTop.blue  = pixelsGrid[i - 2 * (width + 1)].blue  + pixelsGrid[i - (2 * width + 1)].blue  + pixelsGrid[i - 2 * width].blue  + pixelsGrid[i - 2 * width + 1].blue  + pixelsGrid[i - 2 * width + 2].blue ;

        averageColorTop.red   = pixelsGrid[i - (width + 1)].red   + pixelsGrid[i - width].red   + pixelsGrid[i - width + 1].red   + pixelsGrid[i - (width + 2)].red   + pixelsGrid[i - width + 2].red;
        averageColorTop.green = pixelsGrid[i - (width + 1)].green + pixelsGrid[i - width].green + pixelsGrid[i - width + 1].green + pixelsGrid[i - (width + 2)].green + pixelsGrid[i - width + 2].green;
        averageColorTop.blue  = pixelsGrid[i - (width + 1)].blue  + pixelsGrid[i - width].blue  + pixelsGrid[i - width + 1].blue  + pixelsGrid[i - (width + 2)].blue  + pixelsGrid[i - width + 2].blue;

        averageColorMiddle.red   = pixelsGrid[i - 1].red   + pixelsGrid[i + 1].red   + pixelsGrid[i - 2].red   + pixelsGrid[i + 2].red;
        averageColorMiddle.green = pixelsGrid[i - 1].green + pixelsGrid[i + 1].green + pixelsGrid[i - 2].green + pixelsGrid[i + 2].green;
        averageColorMiddle.blue  = pixelsGrid[i - 1].blue  + pixelsGrid[i + 1].blue  + pixelsGrid[i - 2].blue  + pixelsGrid[i + 2].blue;

        averageColorBottom.red   = pixelsGrid[i + (width + 1)].red   + pixelsGrid[i + width].red   + pixelsGrid[i + width + 1].red   + pixelsGrid[i + (width + 2)].red   + pixelsGrid[i + width - 2].red;
        averageColorBottom.green = pixelsGrid[i + (width + 1)].green + pixelsGrid[i + width].green + pixelsGrid[i + width + 1].green + pixelsGrid[i + (width + 2)].green + pixelsGrid[i + width - 2].green;
        averageColorBottom.blue  = pixelsGrid[i + (width + 1)].blue  + pixelsGrid[i + width].blue  + pixelsGrid[i + width + 1].blue  + pixelsGrid[i + (width + 2)].blue  + pixelsGrid[i + width - 2].blue;

        averageColorUnderBottom.red   = pixelsGrid[i + 2 * (width + 1)].red   + pixelsGrid[i + (2 * width + 1)].red   + pixelsGrid[i + 2 * width].red   + pixelsGrid[i + 2 * width - 1].red   + pixelsGrid[i + 2 * width - 2].red;
        averageColorUnderBottom.green = pixelsGrid[i + 2 * (width + 1)].green + pixelsGrid[i + (2 * width + 1)].green + pixelsGrid[i + 2 * width].green + pixelsGrid[i + 2 * width - 1].green + pixelsGrid[i + 2 * width - 2].green;
        averageColorUnderBottom.blue  = pixelsGrid[i + 2 * (width + 1)].blue  + pixelsGrid[i + (2 * width + 1)].blue  + pixelsGrid[i + 2 * width].blue  + pixelsGrid[i + 2 * width - 1].blue  + pixelsGrid[i + 2 * width - 2].blue ;

        averageColor.red   = ( pixelsGrid[i].red   + blurValue * (averageColorTop.red   + averageColorMiddle.red   + averageColorBottom.red))   / 25;
        averageColor.green = ( pixelsGrid[i].green + blurValue * (averageColorTop.green + averageColorMiddle.green + averageColorBottom.green)) / 25;
        averageColor.blue  = ( pixelsGrid[i].blue  + blurValue * (averageColorTop.blue  + averageColorMiddle.blue  + averageColorBottom.blue))  / 25;

        x = i % (height);
        y = (i - x)/width;

        BMPSetColor(image, x, y, averageColor);
    }

}

void exportBMPImageToFile(BMP *image, char *filename) {
    int height;
    int width;
    unsigned char *fileHeader;
    unsigned char *infoHeader;
    Rgb *pixelsGrid;
    Rgb pixel;

    height = image->height;
    width = image->width;

    fileHeader = createBitmapFileHeader(height, width);
    infoHeader = createBitmapInfoHeader(height, width);

    pixelsGrid = image->pixels;

    FILE *imageFile = fopen(filename, "wb");

    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixel = *(pixelsGrid + i * width + j);

            fwrite(&(pixel.blue), sizeof(char), 1, imageFile);
            fwrite(&(pixel.green), sizeof(char), 1, imageFile);
            fwrite(&(pixel.red), sizeof(char), 1, imageFile);
        }
    }

    fclose(imageFile);
}

/**
 * Generate the Bitmap File Header
 *
 * @param height: Height of the image
 * @param width: Width of the image
 *
 * @return unsigned char*:
 */
unsigned char *createBitmapFileHeader(int height, int width) {
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + BYTES_PER_PIXEL * height * width;

    static unsigned char fileHeader[] = {
        0,0, /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize    );
    fileHeader[ 3] = (unsigned char)(fileSize>> 8);
    fileHeader[ 4] = (unsigned char)(fileSize>>16);
    fileHeader[ 5] = (unsigned char)(fileSize>>24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

/**
 * Generate the Bitmap Info Header
 *
 * @param height: Height of the image
 * @param width: Width of the image
 *
 * @return unsigned char*
 */
unsigned char *createBitmapInfoHeader(int height, int width) {
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0, /// number of color planes
        0,0, /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width    );
    infoHeader[ 5] = (unsigned char)(width>> 8);
    infoHeader[ 6] = (unsigned char)(width>>16);
    infoHeader[ 7] = (unsigned char)(width>>24);
    infoHeader[ 8] = (unsigned char)(height    );
    infoHeader[ 9] = (unsigned char)(height>> 8);
    infoHeader[10] = (unsigned char)(height>>16);
    infoHeader[11] = (unsigned char)(height>>24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}
