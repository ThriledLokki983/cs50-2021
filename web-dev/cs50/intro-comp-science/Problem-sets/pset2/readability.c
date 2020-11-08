#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    // Prompting the user for text
    string text = get_string("Text: ");

    // Initializing our integer values for counting letters, words, and sentences
        float letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Indexing and counting the number of letters in the given string
            if (isalpha(text[i]))
            {
                // If letter, go ahead and increase the number of letters we have
                letters++;
            }
            // Counting the number of spaces(words) in the given text by the user
            if (isspace(text[i]))
            {
                // If space, it means we have a word, go ahead and increase word count
                words++;
            }
            // condition that helps to check that we are at the end of a sentence so we count it as such
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
            sentences++;
            }
    }

    // Calculating the grades after collecting the number of letters words and sentences
    float L = letters / words * 100;
    float S = sentences / words * 100;

    // Inducing conditions to print Grades after the user has inputed the text
    float index = roundf(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        // Printing grade if below grade 1
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        //// Printing grade if above 16
        printf("Grade 16+\n");
    }
    else
    {
        //// Printing grade if within range 1-15
        printf("Grade %i\n", (int)index);
    }
}
