#include <stdio.h>
#include <stdlib.h>
//#include <cs50.h>


typedef struct node
{
 int number;
 struct node *next;
}node;

int main(void)
{
 // Always initialize your list to NULL
 node *list = NULL;

node *n =  malloc(sizeof(node));
// check for error
if (n == NULL)
{
 return 1;
}
n -> number = 1;
n -> next = NULL;
list = n;

//AGAIN
n = malloc(sizeof(node));
if (n == NULL)
{
 free(list);
 return 1;
}
n -> number = 2;
n -> next = NULL;
list -> next = n;

//AGAIN
n = malloc(sizeof(node));
if (n == NULL)
{
 free(list -> next);
 free(list);
 return 1; 
}
n ->number = 3;
n -> next = NULL;
list -> next -> next = n;

for (node *tmp = list; tmp != NULL; tmp=tmp->next)
{
 printf("%i\n", tmp->number);
}


// Freeing memory
while (list != NULL)
{
 node *tmp = list ->next;
 free(list);
 list = tmp;
}

}