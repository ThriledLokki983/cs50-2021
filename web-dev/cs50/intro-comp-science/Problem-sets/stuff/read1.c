#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int letter_count(string x);

int main(void)
{
    // Prompting the user for text
    string n = get_string("Text: ");

    int i = 0;
    int lets = 0;
    int space = 1;
    int sent = 0;
    int word = (space + 1);


    // Indexing and counting the number of letters in the given string
    for (i = 0; n[i] != '\0'; i++)
    {
        if (n[i] != '.' && n[i] != ',' && n[i] != ' ' && n[i] != '"' && n[i] != '\'')
        {
             lets++;
        }

    }

    // Counting the number of spaces(words) in the given text by the user
    for (i = 0; n[i] != '\0'; i++)
    {
        if (n[i] == ' ' && n[i+1] != ' ')
        {
            space++;
        }

        // condition that helps to check that we are at the end of a sentence so we count it as such
        if (n[i] == '.' || n[i] == '?' ||  n[i] == '!')
        {
            sent++;
        }
    }
    // Calculating the grades after collecting the number of letters words and sentences
    float L = ((lets * 100) / (space+1));
    float S = ((sent * 100) / (space+1));

    // Inducing conditions to print Grades after the user has inputed the text
    float index = roundf(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade: 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        printf("Grade: %i\n", (int)index);
    }
                 printf("The Text consiste of: %i Character(s) \t %i Word(s) \t %i Sentence(s)\n", lets, space, sent);
                 printf(" Average number of Letters per 100 words is: %i\n", (int)L);
                 printf(" Average number of Sentences per 100 words is: %i\n", (int)S);
}
