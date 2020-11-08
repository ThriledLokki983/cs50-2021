#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompting the user for an input
    int height;
    do
    {
        height = get_int("Height for the pyramid: ");
    }
    // This checks if the given input from the user fulfills our condition (i.e. between 1      & 8 inclusive).
    while (height < 1 || height > 8);

    // Iteration for columns up until the given input from the user has been reach.
    for (int i = 0; i < height; i++)
    {
        // This will print empty spaces helping to realign our blocks to the right.
        for (int k = (height - i) - 1; k >= 1; k--)
        {
            printf(" ");
        }
        // This prints the HASH symbol up until re reach the input from the user.
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // This will print a new line after each iteration prints
        printf("\n");
    }

}
