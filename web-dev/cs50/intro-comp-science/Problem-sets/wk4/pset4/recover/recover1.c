#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Media not found\n");
        return 1;
    }

    // remember filenames
    //char *infile = argv[1];

    // open input file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fprintf(stderr, "Cannot open: %s\n", argv[1]);
        return 2;
    }

    BYTE buffer[512];
    int count = 0;

    char pic_name[8];
    FILE *pic = NULL;

    while (true)
    {
        // read a block of the memory card image
        size_t bytehead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, card);

        // break out of the loop when we reach the end of the card image
        if (bytehead == 0 && feof(card))
        {
            break;
        }

        // check if we found a JPEG
        bool jpg_found = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if we found a yet another JPEG, we must close the previous file
        if (jpg_found && pic != NULL)
        {
            fclose(pic);
            count++;
        }

        // if we found a JPEG, we need to open the file for writing
        if (jpg_found)
        {
            sprintf(pic_name, "%03i.jpg", count);
            pic = fopen(pic_name, "w");
        }

        // write anytime we have an open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytehead, pic);
        }
    }

    // close last jpeg file
    fclose(pic);

    // close infile
    fclose(card);

    // success
    return 0;
}
