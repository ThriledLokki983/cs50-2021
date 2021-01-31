#include <stdio.h>
#include <cs50.h>

int main(void)
{
 // Get an integer from the user
 int num1 = printf("x: ");
 scanf("%d", &num1);

 // Get an integer from the user
 int num2 = printf("y: ");
 scanf("%d", &num2);

 // Print out the result from the operation used
 printf("X + Y = %d\n", num1 + num2);
 return 0;
}