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
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
