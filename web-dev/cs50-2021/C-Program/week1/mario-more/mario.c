#include <stdio.h>
#include <cs50.h>

int main(void)
{
 // Prompting the user for an input
 int height;

 do{
  height = get_int("Height: ");
 }
 // Check if input fulfills our condition 
 while (height < 1 || height > 8);

 for(int i = 0; i < height; i++)
 {

  // Printing the spaces to create a perfect pyramid
  for (int j = (height - i) - 1; j >= 1; j--)
  {
   printf(" ");
  }

  // Printing the HASHES to represent the pyramid
  for (int k = 0; k <= i; k++)
  {
   printf("#");
  }

  // Mirroring the exact opposite of the pyramid above
  for (int c = (height + 0); c <= height; c++)
  {
   printf(" ");
  }
  for (int l = 1; l <= i + 1; l++)
  {
   printf("#");
  }
  printf("\n");
 }
 
}