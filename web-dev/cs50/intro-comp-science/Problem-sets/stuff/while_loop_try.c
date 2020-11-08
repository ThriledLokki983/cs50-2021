#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int day = 1;
    float amount = 0.1;

    while(day <= 31){
        printf("Day: %i \t  Amount: $%.2f\n", day, amount);
        day++;
        amount *= 2;
    }
   return 0;
}