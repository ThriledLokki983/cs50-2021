#include <stdio.h>
#include <cs50.h>
#include <string.h>
//void cipher(string x);

int main(int argc, char *argv[])
{
    int i, j, txt, number;
    string text;


    if (argc != 2)
    {
         printf("Usage: ./caesar key\n");
        return 1;
    }

    for (j = 0; j < strlen(argv[1]); j++)
    {
        if ((int)argv[j] >= 0 && (int)argv[j] <= 9)
        {
                printf("Usage: ./caesar key\n");
                return 1;
        }
    }


   text = get_string("plaintext: ");

            int number = printf("%i", *argv[1]);
             number = *argv[1];
            int temp = *number;
            //int *p = &n;
            printf("%i\n", temp);

   // at this point, the program does not correctly pick the int @ arg[1] // Figure out why!!!! Find  a way to tell the computer to goto argv[1] and pick wahtever value is there to work with
   // AFter that, the program is ready to be sent.
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
