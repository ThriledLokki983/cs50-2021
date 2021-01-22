#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
 // Check for the correct execution of the program
  if (argc != 2)
  {
   fprintf(stderr, "Media card not found\n");
   return 1;
  }

  // Open the card and check if its not empty
  FILE *card = fopen(argv[1], "r");

  // Check if image cannot be open
  if (card == NULL)  
  {
   fprintf(stderr, "Cannot open: %s\n", argv[1]);
   return 1;
  }
 
  // 512 bytes to read until end of file
  BYTE buffer[512];

  // Set the file to write the jpeg stuff to
  FILE *pic = NULL;

 // Set a counter to track the number of photos found.
  int count = 0;

  // Set the size to write the name of each jpeg file to be recovered
  char pic_name[8];

 // since we don't know how many times we will be reading, the while loop is the best choice, keep reading until something we dont want
 // This was crazy cos i did not know you could set a bool to true. it took some time to figure this out with all kinds of error msg.
 while (true)
 {
   // Calc the size of the card
   size_t Byteheader = fread(buffer, sizeof(BYTE), BLOCK_SIZE, card);

  /* Stop when end of the card is reached*/
  if (Byteheader == 0 && feof(card))
  {
   break;
  }

  // Check the first 4 bytes if it is a jpeg
  bool jpg_found = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

  // Increase count if jpeg found
  if (jpg_found && pic != NULL)
  {
   fclose(pic);
   count++;
  }

  if (jpg_found)
  {
   // Formatting the name of every jpeg we find on the card
   sprintf(pic_name, "%03i.jpg", count);

   pic = fopen(pic_name, "w");
  }

  if (pic != NULL)
  {
   // Keep writing bytes to the open file pic
   fwrite(buffer, sizeof(BYTE), Byteheader, pic);
  }
 }

 // Close all opened files and free memory
 fclose(pic);
 fclose(card);
 return 0;
}