#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
void cipher(string x);


int main(int argc, string argv[])
{
    int t = (int)argv[1];

    if (argc != 2)
    {
         printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((int)argv[i] >= 0 && (int)argv[i] <= 9)
        {
                printf("Usage: ./caesar key\n");
                return 1;
        }
    }
    //printf("Success\n%s\n", argv[1]);
    string text = get_string("Text: ");

    printf("plaintext: %s\n", text);
     printf("ciphertext: ");
    for (int j = 0, n = strlen(text); j < n; j++)
    {
         printf("%i", text[j] + t);
    }
   printf("\n");
}
// printf("%c", s[i]);
// if (text[j] >= 'a' && text[j] <= 'z')

