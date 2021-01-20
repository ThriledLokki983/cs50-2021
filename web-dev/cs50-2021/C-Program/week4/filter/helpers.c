#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define BLUR 3
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates over the rows
    for (int i = 0; i < height; i++)
    {
        // Iterates over the columns
        for (int j = 0; j < width; j++)
        {
            // Get each individual pixel and assign it to an int variable
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calc the average for ou pixles
            int average = round(((float)red + (float)green + (float)blue)/3.0);

            // Set the new average as our new pixel color
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        } 
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the individual pixels
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // Calc the new sepia color for each
            float new_red = fmin(255, (red * 0.393) + (green * 0.769) + (blue * 0.189));
            float new_green = fmin(255, (red * 0.349) + (green * 0.686) + (blue * 0.168));
            float new_blue = fmin(255, (red * 0.272) + (green * 0.534) + (blue * 0.131));

            // Set the new values to our pixels
            image[i][j].rgbtRed = (int)(round(new_red));
            image[i][j].rgbtGreen = (int)(round(new_green));
            image[i][j].rgbtBlue = (int)(round(new_blue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < ((float)(width)/2); j++)
        {
            RGBTRIPLE new_image = image[i][j];

            // Starting with the swaping on the horizontal opposite sides
            image[i][j] = image[i][width + (-j - 1)];
            image[i][width + (-j -1)] = new_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int count = 0;
    double average_red, average_green, average_blue;
     RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = average_green = average_red = count = 0;

            // Grab the old color values of all of the 9 pixelsthat forms a grid of the original pixel (Box Blur)
            for (int k = i - ((BLUR - 1) / 2); k < i + ((BLUR - 1) / 2); k++)
            {
                for (int l = j - ((BLUR - 1) / 2); l < j + ((BLUR - 1) / 2); l++)
                {
                    if ((k >= 0 && l < height) && (l >= 0 && l < width))
                    {
                        average_red += image[k][l].rgbtRed;
                        average_green += image[k][l].rgbtGreen;
                        average_blue += image[k][l].rgbtBlue;
                        count++;
                    }
                }
            }  

            if (count != 0)
            {
                average_red = round(average_red / (double)count);
                average_green = round(average_green / (double)count);
                average_blue = round(average_blue / (double)count);

                new_image[i][j].rgbtRed = average_red;
                new_image[i][j].rgbtGreen = average_green;
                new_image[i][j].rgbtBlue = average_blue;
            }
            else
            {
                return;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }   
    }
    return;
}
