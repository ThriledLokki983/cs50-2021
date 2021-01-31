#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
 int i = get_positive_int();
 printf("%i\n", i);
}

// Get a number from user
int get_positive_int(void)
{
 int n;
 do 
 {
  n = get_int("Positive Integer Here: ");
 }
 while(n < 1);
 return n;
}