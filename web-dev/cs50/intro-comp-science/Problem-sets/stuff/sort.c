#include <stdio.h>
#include <cs50.h>
void swap(int *a, int *b);

int main(void)
{

    int n, a, i, j;

    int num[4] = {4, 7, 2, 8};

    for (i = 0; i < 3; i++)
    {
        int min = i;
        for(j = (i + 1); j < 4; j++)
            {
            if (a[j] < a[min])
            {
                min = j;
            }
    }
        if (min != i)
        {
            //swap(num[j], num[min]);
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
             printf("%i", tmp);

        }
    //temp = a[i];
    //a[i] = a[min];
    //a[min] = temp;

    }
    printf("The numbers arranged in ascending order are given below \n");

    for (i = 0; i < 4; ++i)

            printf("%i\n", num[i]);

}


 void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
