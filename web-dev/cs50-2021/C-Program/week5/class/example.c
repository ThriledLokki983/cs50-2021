#include <stdio.h>
#include <cs50.h>

// STRUCT
// . & *
// ->
// LINKED LIST ==> [data structure - it can grow and shrink] a list of data that helps to solve a problem (storing a number of data)

typedef struct data
{
 // this is our number - variable
 int number;

 // A pointer to another/next number // This creates a node structure to link the numbers contiguously
 struct data *next;
}data;


int main(void)
{
 //This will create an empty linked list 
 node *list  = NULL;

// Ask malloc to allocate a space in memory to store your data // Malloc will always return an address of the block of memory allocated
node *n = malloc(sizeof(node));

if (n != NULL)
{
 // go to the struct and the variable there and put 1 there.
 n -> number = 1;

 // Follow the arrow and set the value to NULL
 n -> next = NULL;
}

// Adding the values to our link list
list = n;

//ANOTHER
node *n = malloc(sizeof(node));
if (n != NULL)
{
 n -> number 2;
 n -> next = NULL;
}
list -> next -> n;

//ANOTHER
node *n = malloc(sizeof(node));
if (n != NULL)
{
 n -> number = 3;
 n -> next = NULL;
}
list -> next -> next -> n;


/*
 TREES
 Binary Search trees
 Running time for INSERTING into binary search ==>O(log n)
*/
typedef struct node
{
 int number;
 struct node *left;
 struct node *right;
};

/*

TRIES - it is a tree each of whose node is an array of pointers
Search time = O(1) // constant time
*/


/*
ARRAY
----------------
insertion is bad
Deletion is bad
Lookup is great
Relatively easy to sort
Relatively small size-wise
Stuck with a fixed, no flexibility
*/


/*
LINKED-LIST
------------
Insertion is easy
Deletion is easy
Lookup is bad
Relatively difficult to sort
Relatively small size-wise
*/



/*
TRIES 
---------------
Insertion is complex
Deletion is easy
Lookup is fast
Already sorted
Rapidly becomes huge, even with little data present, not great if space is premium
*/
} 
