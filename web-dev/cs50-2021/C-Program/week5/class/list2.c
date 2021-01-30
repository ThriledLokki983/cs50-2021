#include <stdio.h>
#include <stdlib.h>

/*
/////////////
Starts of with an array of size 3 having it dynamically allocated & then resizes it to an array of size 4 by copying the old into the new and the freeing the old then proceeding as before
\\\\\\\\\\\\\
*/

int main(void)
{

 // dynamically allocating a chunk of memory
 int *list = malloc(3 * sizeof(int));

 if (list ==NULL)
 {
  return 1;
 }

 list[0] = 1; // *list = 1;
 list[1] = 2; // *(list + 1) = 2;
 list[2] = 3; // *(list + 2) = 3;

 int *tmp = malloc(4 * sizeof(int));
 // int *tmp = realloc(list, 4 * sizeof(int)); // Take back the old memory and resize it

 //Always do this check after allocating a memory
 if (tmp == NULL)
 {
  free(list);
  return 1;
 }

 for (int i = 0; i < 3; i++)
 {
  // Copy what is in the old array (list[]) into the new array (tmp[])
  tmp[i] = list[i];
 }

 tmp[3] = 4;

 free(list);
 list = tmp;

 for (int i = 0; i < 4; i++)
 {
  printf("%i\n", list[i]);
 }

 free(list);
 
}