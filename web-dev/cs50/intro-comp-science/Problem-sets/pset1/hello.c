#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompting the user for input
    string name = get_string("What is your name?\n");

    //Saying hello + whatever the user gave as input
    printf("hello, %s\n", name);
}

