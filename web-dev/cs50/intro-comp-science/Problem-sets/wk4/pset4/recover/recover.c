#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define BLOCK_SIZE 512


typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //char *free = true;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    char *input = argv[1];

    FILE *file = fopen(input, "r");

    if (file == NULL)
    {
        fprintf(stderr, "can't open %s\n", input);
        return 2;
    }


    // Repeat this process until end of card
    //unsigned char bytes[512*100];
    BYTE bytes[512];
    int count = 0;
    //char *pic;

    char photo[8];
    FILE *output = NULL;

    while (true)
    {
        // Calc the size of the card
        size_t end = fread(bytes, sizeof(BYTE), BLOCK_SIZE, file);

        // stop this loop if
        if (end == 0 && feof(file))
        {
            break;
        }

        // Check first four bytes at the beginging of a block
         bool pic = bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0;

        if (pic && file != NULL)
        {
            fclose(output);
            count++;
        }

        if (pic)
        {
            sprintf(photo, "%03i.jpg", count);
            output = fopen(photo, "w");
        }

        if (output != NULL)
        {
            fwrite(bytes, sizeof(BYTE), end, output);
        }
    }

    fclose(output);
    fclose(file);

    return 0;
}
