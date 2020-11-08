#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
//void cipher(string x);

int main(int argc, char *argv[])
{
    int i, txt, number;
    string text;

    if (argc != 2)
    {
         printf("Usage: ./caesar key\n");
        return 1;
    }

    text = get_string("plaintext: ");
    for (int k = 0; argv[k] != '\0'; k++)
    {
        if (argv[k] != 'a' && argv[k] != 'z')
        {
            int number = argv[1];
        }
    }
    printf("Usage: ./caesar key");
    number = atoi (argv[1]);


    for (i = 0; text[i] != '\0'; i++)
    {
        txt = text[i];
        if (txt >= 'a' && txt <= 'z')

        {
            txt = txt + number;
            if (txt > 'z')
            {
                txt = txt - 'z' + 'a' - 1;
            }
            text[i] = txt;
        }
        else if (txt >= 'A' && txt <= 'Z')
        {
            txt = txt + number;
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






