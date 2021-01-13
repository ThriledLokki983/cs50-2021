#include <stdio.h>
#include <cs50.h>

int main(void)
{
 char name[25];
 // string answer = get_string("What is your name?");
 // Get input from user
 printf("What is your name?\n");

 // Get the input from the user
 scanf("%s", name);

 // Print the name
 printf("Welcome, %s\n", name);
 return 0;
}