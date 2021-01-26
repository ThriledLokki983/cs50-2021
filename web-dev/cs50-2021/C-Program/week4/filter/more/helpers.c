#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <cs50.h>
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
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
{int count = 0;
    double average_red, average_green, average_blue;
     RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = average_green = average_red = count = 0;

            // Grab the old color values of all of the 9 pixelsthat forms a grid of the original pixel (Box Blur)
            for (int k = i - ((3 - 1) / 2); k <= i + ((3 - 1) / 2); k++)
            {
                for (int l = j - ((3 - 1) / 2); l <= j + ((3 - 1) / 2); l++)
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //create temporary values to store the calculations
    float sumBlueY;
    float sumGreenY;
    float sumRedY;
    float sumBlueX;
    float sumGreenX;
    float sumRedX;
    float modifierX;
    float modifierY;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //Resets values for every pixel
            sumBlueY = 0.0;
            sumGreenY = 0.0;
            sumRedY = 0.0;
            sumBlueX = 0.0;
            sumGreenX = 0.0;
            sumRedX = 0.0;

            // sums values of the pixel and 8 neighboring ones after applying a modifier, skips iteration if it goes outside the pic
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

                    // calculates modifiers for vertical and horizantal borders
                    modifierX = (k + 1 * k - k * abs(h));
                    modifierY = (h + 1 * h - h * abs(k));

                    sumBlueX += image[j + k][i + h].rgbtBlue * modifierX;
                    sumGreenX += image[j + k][i + h].rgbtGreen * modifierX;
                    sumRedX += image[j + k][i + h].rgbtRed * modifierX;

                    sumBlueY += image[j + k][i + h].rgbtBlue * modifierY;
                    sumGreenY += image[j + k][i + h].rgbtGreen * modifierY;
                    sumRedY += image[j + k][i + h].rgbtRed * modifierY;
                }
            }

            // obtains the final values of the pixels combining X and Y calculations
            temp[j][i].rgbtBlue = limit(round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY)));
            temp[j][i].rgbtGreen = limit(round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY)));
            temp[j][i].rgbtRed = limit(round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY)));
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