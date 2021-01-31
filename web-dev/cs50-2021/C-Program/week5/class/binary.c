#include <stdio.h>
#include <stdlib.h>

 /*
 Implementing a binary search algorithm
 */

typedef struct node
{
 int number;
 struct node *tree;
}node;

int main(void)
{


 
}

// Our function // Recurssion

bool search(node *tree, int number)
{

 // Always check for NULL to avoid program crashing
 if (tree == NULL)
 {
  return false;
 }

 else if (number < tree -> number)
 {
  return search(tree ->left, number);
 }
 else if (number > tree -> number)
 {
  return search(tree -> right, number);
 }

else if (number == tree ->number)
{
 return true;
}

// or
/* 
else
{
 return true;
}
*/


// Insert to the node // Return a pointer to the newly inserted node
node *insert (node *tree, int number); 

// STEPS
//Allocate space for the new node using malloc
// CHeck to make sure we have not run out ofmemory
// Populate and insert the node at the begining of the loinked list
// Return a pointer to the new head of the linked list

// Deleting an entire linked list
void destroy(node *tree);

//STEPS
// If NULL, then stop
// Delete the rest of the list
// Free the current node


}