#include "helpers.h"
#include <math.h>


RGBTRIPLE square(int j, int i, int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed = 0;
    int sumGreen = 0;
    int sumBlue = 0;
    int count = 0;

    for(int h = j-1; h <= j + 1; h++)
    {
        for(int w = i-1; w <= i + 1; w++)
        {
            if(w >= 0 && w < width && h >= 0 && h < height)
            {
                sumRed += image[h][w].rgbtRed;
                sumGreen += image[h][w].rgbtGreen;
                sumBlue += image[h][w].rgbtBlue;
                count++;
            }
        }
    }

    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round(sumRed/count);
    blurred_pixel.rgbtGreen = round(sumGreen/count);
    blurred_pixel.rgbtBlue = round(sumBlue/count);

    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            new_image[j][i] = square(j, i, height, width, image);
        }
    }

    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            image[j][i] = new_image[j][i];
        }
    }
}

