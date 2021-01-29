// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    // Copy header from input file to output file // 
    // Bytes to read until end of file
    int16_t sample;
    uint8_t header [HEADER_SIZE];

        fread(header, HEADER_SIZE, 1, input);
        fwrite(header, HEADER_SIZE, 1, output);

     // Read samples from input and write updated data output file
    while (fread(&sample, sizeof(int16_t), 1, input))
    {
        // Update the volume
        sample *= factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }
    

    // Close files
    fclose(input);
    fclose(output);

    return 0;
 
    //
}
