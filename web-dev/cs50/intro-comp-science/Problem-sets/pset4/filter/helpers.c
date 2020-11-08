
////#include "filter.c"
#include "helpers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
       // Iterate over the rows within the picture to be loaded
    for (int i = 0; i < height; i++)
    {
        // Iterates over the columns within the picture to be filtered
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

             // we calculate the average value from the values we just acquired and setting it to a new variable.
            int average = round(((float)red + (float)green + (float)blue) / 3.0);

                // Set the new value for all the individual colors(thats how to get a grayscale)
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
            // Getting the pixels from the image
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;

            float new_red = fmin(255, (r * 0.393) + (g * 0.769) + (b * 0.189));
            float new_green = fmin(255, (r * 0.349) + (g * 0.686) + (b * 0.168));
            float new_blue = fmin(255, (r * 0.272) + (g * 0.534) + (b * 0.131));

            // rounding the values
            float newR = round(new_red);
            float newG = round(new_green);
            float newB = round(new_blue);

            int newR1 = newR;
            int newG1 = newG;
            int newB1 = newB;

            // Set our new values to the individual pixels from our file
            image[i][j].rgbtRed = newR1;
            image[i][j].rgbtGreen = newG1;
            image[i][j].rgbtBlue = newB1;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through the rows of the RGBT file
        for (int i = 0; i < height; i++)
        {
            // Iterates through each column also
            for (int j = 0; j < round((float)(width)/2); j++)
            {
                // Creating a temp RGBTRIPLE
                RGBTRIPLE new_image = image[i][j];

                // Starting with the swaping on the horizontal opposite sides
                image[i][j] = image[i][width + (-j - 1)];

                image[i][width +(-j - 1)] = new_image;
            }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float r, g, b;
            int count = 0;

            for (int a = i - 1; a < i + 2; a++)
            {
                for (int t = j - 1; t < j + 2; t++)
                {
                    if (a < 0 || t < 0)
                        continue;
                    {
                        r = image[a][t].rgbtRed;
                        g = image[a][t].rgbtGreen;
                        b = image[a][t].rgbtBlue;
                        count++;
                    }
                }
            }

            // assign back the values acquired
            new_image[i][j].rgbtRed =  fmin(255, round( (float)r / count));
            new_image[i][j].rgbtGreen =  fmin(255, round( (float)g / count));
            new_image[i][j].rgbtBlue =  fmin(255, round((float) b / count));
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
        }
    }
    return;
}
