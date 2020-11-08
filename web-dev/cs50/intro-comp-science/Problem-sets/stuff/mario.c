#include <stdio.h>
#include <cs50.h>
#include <string.h>

void draw(int x);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height of you pyramid: ");
    }
    while (height < 1 || height > 8)

    darw(height);
}

void draw(int x)
{
    if(x == 0)
    {
        return;
    }
    draw(h - 1);

    // Drawing the row of ##
    for (i = 0; i < x; i++)
    {
        printf("#");
    }
    printf("\n");

}