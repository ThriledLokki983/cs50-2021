// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// initialise positive hash value using unsigned int 
unsigned int hash_value;

// initialise (positive) hash table word count 
unsigned int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    // Hash the word to get a hash_value
    hash_value = hash(word);

    // Access the linked list
    node *cur = table[hash_value];

    // Iterate throught the linked list
    while (cur != NULL)
    {
        /* check if word if found in dict */
        if (strcasecmp(word, cur ->word) == 0)
        {
            /* return true, otherwise return false*/
            return true;
        }
        cur = cur ->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // http://www.cse.yorku.ca/~oz/hash.html ==> Hash function --Dan Bernstein

    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary to be used
    FILE *file = fopen(dictionary, "r");

    // Error checking
    if (file == NULL)
    {
        return false;
    }

    // Make space for words to be searched for
    char word[LENGTH + 1];

    // Search through the file until EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        // Check for error
        if (n == NULL)
        {
            return 1;
        }

    // Set a pointer to the word and the next node
    strcpy(n -> word, word);

    // Hash the newly found word for a hash value
    hash_value = hash(word);

    // Set a new pointer 
    n ->next = table[hash_value];

    // Set the head to the new pointer
    table[hash_value] = n;

    // Increase word count
    word_count++; 
    }
    
    // Close file
    fclose(file);
    
    // If dictionary was successfully loaded, return true, else return false
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{    
    // Check for words 
    if (word_count > 0)
    {
        return word_count; 
    }
    // otherwise
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
      // Iterate though the buckets we have
      for (int i = 0; i < N; i++)
        {
                /* Set cur to each bucket list */
                node *cur = table[i];

            /* If cur is NULL, start freeing */
            while (cur)
            {
                /* create a temporary pointer to traverse */
                node *tmp = cur;

                /* Move cursor to the next node */
                cur = cur -> next;

                // Now free tmp
                free(tmp);
            }
            /* However, if cur is NULL */
            if (i == N - 1 && cur == NULL)
            {
                return true;
            }
        }
      return false;
}
