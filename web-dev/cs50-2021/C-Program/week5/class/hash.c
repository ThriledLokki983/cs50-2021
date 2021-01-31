#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int HASH_MAX = 26;
#define LENGTH 45
unsigned int hash(const char *word);

/*
HASH TABLES - data structure (ArraY OF LINKED LIST) ==> Running time = O(1) // Asymptotically  = O(n)

HASH FUNCTION - takes input string (char *) and returns a number (int) - helps to get data more quickly
looking at the first string may lead to COLLISION
Therefore, we can look beyond the first letter 
-----------------
HASH TABLES
-----------------
-Insertion is a two-step process
-Deletion is easy
-Lookup is on average better than linked-list
-Not an ideal data structure if sorting is the goal -- array will better
-Can run the gamut of size

1. A combination of 2 things
- Hash function
- Array

A good hash function
*Use only the data being hashed and all the data being hashed
*Be deterministic
*Uniformly distribute data
*Generate very different hash codes for very similar data
*/

typedef struct head
{
 char word[LENGTH + 1];
 struct head *next;
}head;

const int N = 26;
head *table[N];


int main(void)
{

 head *list = NULL;

 char name[20];
 printf("What is your name: ");
 char result = scanf("%s", name);

 for (int i = 0; result[i] != '\0'; i++)
 {
   tmp[] = result[i];

 }
 


 hash(name);
 printf("Your HASH_CODE: %i\n", (int)hash);
 
// Allocate memory and copy the word into the node 

    head *n = malloc(sizeof(head));
    if (n == NULL)
    {
      return 1;
    }
    strcpy(n-> word, name);
    n ->next = NULL;
    return 0;
 
 for (head *tmp = list; tmp != NULL; tmp=tmp->next)
{
 printf("%s\n", tmp->word);
}


// Freeing memory
while (list != NULL)
{
 head *tmp = list ->next;
 free(list);
 list = tmp;
}

}

// HASH FUNCTION

unsigned int hash(const char *word)
{
 int sum = 0;
 for (int i = 0; i < word[i] != '\0'; i++)
 {
  sum += word[i];
 }
 return sum % N;
}