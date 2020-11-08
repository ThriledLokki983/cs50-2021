// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    bool is_word;
    struct node *next[27];
}
node;

node* first;
int count = 0;

int get_index(char c);
node *init_ptr();
bool unload_helper(node* node_ptr);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    node *node_ptr = first;
    for (int i = 0, n = strlen(word); i <= n; i++)
    {
        if(word[i] == '\0')
        {
            if (node_ptr -> is_word == true)
                return true;
            else
                return false;
        }

        int index = get_index(word[i]);
        if(node_ptr -> next[index] == NULL)
            return false;

        node_ptr = node_ptr -> next[index];
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the dict
    FILE* dict_file = fopen(dictionary, "r");

    if (dict_file != NULL)
    {
        // Inistialize to get the characters from the dictioary untill EOF
        first = init_ptr();
        int index;
        node* node_ptr = first;

        for (char c = fgetc(dict_file); c != EOF; c = fgetc(dict_file))
        {
            // check for end of word
            if (c != '\n')
            {
                // indexing
                index = get_index(c);
                if (node_ptr -> next[index] == NULL)
                {
                    node_ptr-> next[index] = init_ptr();
                }
                node_ptr = node_ptr -> next[index];
            }
            else
            {
                // check and mark EOW
                node_ptr -> is_word = true;
                //increament count to indicate a wourd found in dict_file
                count++;
                // go back to homebase
                node_ptr = first;
            }
        }
    }
    return true;
}

/*
*returns the index corresponding to the character entered
*/
int get_index(char c)
{
    if (c == '\'') // last index
         return 2;
    else if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';
    // error index
    return -1;
}
/*
*Return a pointer to a node with initial values all set to NULL
*/
 node* init_ptr()
 {
     node* node_ptr = malloc(sizeof(node));
     node_ptr -> is_word = false;
     for (int i = 0; i < 27; i++)
     {
         node_ptr -> next[i] = NULL;
     }
     return node_ptr;
 }
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
   if(unload_helper(first))
       return true;
   return false;
}

bool unload_helper(node* node_ptr)
{
    for (int i = 0; i < 27; i++)
    {
         if (node_ptr->next[i] != NULL)
        {
            unload_helper(node_ptr->next[i]);
        }
    }
    free(node_ptr);
    return true;
}
