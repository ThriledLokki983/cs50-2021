#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
 int i, j, txt, number;
 string text;

 if (argc != 2)
 {
  printf("Usage: ./ceaser key\n");
  return 1;
 }

 for (j = 0; j < strlen(argv[1]); j++)
 {
  if (!isdigit(argv[1][j]))
  {
   printf("Usage: ./ceaser key\n");
   return 1;
  }
 }

 text = get_string("plaintext: ");
 number = atoi(argv[1]);

 for(i = 0; i < text[i]; i++)
 {
  txt = text[i];
  if (txt >= 'a' && txt <= 'z')
  {
   txt = txt + number % 26;
   if (txt > 'z')
   {
    txt = txt - 'z' + 'a' - 1;
   }
   text[i] = txt;
  }

  else if (txt >= 'A' && txt <= 'Z')
  {
   txt = txt + number % 26;
   if (txt > 'Z')
   {
    txt = txt - 'Z' + 'A' - 1;
   }
   text[i] = txt;
  }
 }

 printf("ciphertext: %s\n", text);
 return 0;
}