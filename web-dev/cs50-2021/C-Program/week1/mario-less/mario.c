#include <stdio.h>
#include <cs50.h>


// This is the mario-less program 


int main(void)
{
 // Prompt user for an input
 int height;
 do
 {
  /* code */
  height = get_int("Height of for the Pyramid: ");
 } while (height < 1 || height > 8);

 // Iteration for columns up until the given input by the user
 for (int i = 0; i < height; i++)
 {
  // This will print an empty spaces helping to realign our blocks to the right
  for (int j = (height - i) - 1; j >= 1; j--)
  {
   printf(" ");
  }

  // Printing the HASHES
  for (int k = 0; k <= i; k++)
  {
   printf("#");
  }

  // Move to the next line after each execution
  printf("\n");
 }
 
}