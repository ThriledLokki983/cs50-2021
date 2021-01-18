#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

            // Set the results to a new variable to be used later
            int red1 = round(new_red);
            int green1 = round(new_green);
            int blue1 = round(new_blue);

            // Set the new values to our pixels
            image[i][j].rgbtRed = red1;
            image[i][j].rgbtGreen = green1;
            image[i][j].rgbtBlue = blue1;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
