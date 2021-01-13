#include <stdio.h>
#include <cs50.h>

int main(void)
{
 int n = get_int("Input the width of the block...\n");
 for (int i = 0; i < n-1; i++)
 {
  for (int j = 0; j < n-1; j++)
  {
   printf("*");
  }
  printf("\n");
 }
}