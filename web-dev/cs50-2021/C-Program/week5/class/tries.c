#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
---------------
TRIES 
---------------
Insertion is complex
Deletion is easy
Lookup is fast
Already sorted
Rapidly becomes huge, even with little data present, not great if space is premium

The path from a central ROOT node to a LEAF node

***INSERTION
----------
Simply build the correct path from the root to the leaf

*/

//Our data structure with a new root node called [head_trie] contains a name of a university and an array of 10 pointers to other nodes [head_trie]
// Set root node Globally and set a pointer to this global root

typedef struct head_trie
{
 char university[20];
 struct head_trie *paths[26];
}head_trie;


int main(void)
{

 head_trie *list = NULL;

 head_trie *uni = malloc(sizeof(head_trie));
 if (uni == NULL)
 {
  return 1;
 }


uni->university = strcpy("Harvard");
 for (int i = 0; uni[i] != '\0' ; i++)
 {
  txt = uni[i];
  if (txt >= 'a' && txt <= 'z')
  {
   return txt - 'a';
  }
  else if (txt >= 'A' && txt <= "Z")
  {
   return txt - 'A'
  }
  
 }
 

 

}
