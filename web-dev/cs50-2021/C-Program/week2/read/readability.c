#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
 // Prompt the user for an input
 string text = get_string("Text: ");

 // Initializing our integer values for counting letters, words, and sentences
 float letters = 0, words = 1, sentences = 0;

 for (int i = 0, n = strlen(text); i < n; i++)
 {
  // Indexing and counting the number of letters in a given string 
  if(isalpha(text[i]))
  {
   // If a letter is found, add to the letters we already have.
   letters++;
  }

  // Counting the number of spaces(words) in the given text by the user
  if (isspace(text[i]))
  {
   // If space, it means we have a word, we go ahead and increase our word count
   words++;
  }

  // Conditions that helps to check that we are at the end of the a sentence
  if(text[i] == '.' || text[i] == '!' || text[i] == '?')
  {
   // If the above symbols are found, we are at the end of a sentence, increase our sentence count
   sentences++;
  }
 }

 // Calculating the grades after getting letters/words & sentences
 float L = letters / words * 100;
 float S = sentences / words * 100;

 // Conditions to print the grades
 float index = round(0.0588 * L - 0.296 * S - 15.8);
 if (index < 1)
 {
  // Print corresponding Grade
  printf("Before Grade 1\n");
 }
 else if (index >= 16)
 {
  // Print the corresponding grades withing 1-15
  printf("Grade 16+\n");
 }
else
{
 // Print the exact grade depending on the index
 printf("Grade %i\n", (int)index);
}
return 0;
}