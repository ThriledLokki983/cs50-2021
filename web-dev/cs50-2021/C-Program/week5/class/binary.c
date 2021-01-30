#include <stdio.h>
#include <stdlib.h>

 /*
 Implementing a binary search algorithm
 */

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


}