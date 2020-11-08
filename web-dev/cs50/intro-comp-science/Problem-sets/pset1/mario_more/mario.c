#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Prompting user for input
        height = get_int("Height: \a");
    }
    
    // Check if input fulfills our condition
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int k = (height - i) - 1; k >= 1; k--)
        {
            printf(" ");
        }
        // for (int f = (k-1); f <= k-1; f++)
        
        
        for (int j = 0; j <= i; j++)
        {
            // Printing ## to represent the pyramid we are drawing
            printf("#");
        }
        
        // This is the space provided to separate the flip side of the pyramid. 
        int c;
        for (c = (height + 0 ); c <= height; c++)
        {
            printf("  ");
        }
        
        // This creates the flip side of the pyramid. It is the firt thign I created
        for (int l = 1; l <= i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }  
}


