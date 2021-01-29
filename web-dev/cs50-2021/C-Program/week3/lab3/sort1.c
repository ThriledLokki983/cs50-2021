#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

void swap (int *a, int *b);

int main(int argc, char *argv[])
{
 int *line = 0;
 size_t len = 0;
 ssize_t read;

 if(argc != 2)
 {
  printf("Error! Provide file name: \n");
 }
  FILE *file = fopen(argv[1], "r");
  if(!file)
  {
   fprintf(stderr, "Error!: [- %s -]\nInvalid file!\n", argv[1]);
   return 1;
  }

  while((read = getline(&line, &len, file)) != -1)
  {
     printf("%s", line);
  }
free(line);
exit(EXIT_SUCCESS);
}

void swap (int *a, int *b)
{
 int temp = * a;
 *a = *b;
 *b = temp;
}