#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512



typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checking that the program is executed with exactly one command-line argument
    if (argc != 2)
    {
        // check proper usage
        fprintf(stderr, "Media card not found\n");
        return 1;
    }

    // Open the card.raw and check for NULL
    FILE *card = fopen(argv[1], "r");

    // f the forensic image cannot be opened
    if (card == NULL)
    {
        fprintf(stderr, "Cannot open: %s\n", argv[1]);
        return 1;
    }

    // 512 bytes to be read until end of file
    BYTE buffer[512];

    // set the file to write the jpg stuff to
    FILE *pic = NULL;

    // counter for the number of photots we will find
    int count = 0;

    // set size write the name of each jpg file we find on the card
    char pic_name[8];

    // since we don't know how many times we will be reading, the while loop is the best choice, keep reading until something we dont want
    // This was crazy cos i did not know you could set a bool to true. it took some time to fiqure this out with all kinds of error msg.
    while (true)
    {
        // Calc the size of the card
         size_t Byteheader = fread(buffer, sizeof(BYTE), BLOCK_SIZE, card);

         // if we get to end of the card, sprogram should stop
        if (Byteheader == 0 && feof(card))
        {
            break;
        }

        // Check the first four bytes if it is jpg or not
        bool jpg_found = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // Increase the counter if jpg found
           if (jpg_found && pic != NULL)
           {
               fclose(pic);
               count++;
           }

            if (jpg_found)
            {
                // Formating the name of every jpg found on the card
                sprintf(pic_name, "%03i.jpg", count);


                // If jpg is indeed found, write it to file (pic)
                pic = fopen(pic_name, "w");
            }

            if (pic != NULL)
            {
                // Keep writing bytes to the opened file pic
                fwrite(buffer, sizeof(BYTE), Byteheader, pic);
            }
        }

    // Close all files and free memory
    fclose(pic);
    fclose(card);

    return 0;
}
