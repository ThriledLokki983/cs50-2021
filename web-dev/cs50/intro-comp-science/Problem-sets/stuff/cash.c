#include <stdio.h>
#include <cs50.h>
#include <math.h>
int LEN = 4;
//void least_coins(int x);


int main(void)
{
    int coins[4] = {25, 10, 5, 1};
    float dollar;
    int count;
    int number = 0;
    // This prompts the user of what amount he/she is expecting
    do
    {
        dollar = get_float("Change owed: ");
    }
    // The condition that that the user must fulfil before the algorithm will execute. 
    while (dollar < 0);
    
    // Converting the Dollar value into coin value.
    int change = round(dollar * 100);

    // Creating our for-loop to calculate the amount to be given without doing it one-by-one
    for (int i = 0; i < LEN; i++)

    {
        if (coins[i] <= change)
        {
            // This will loop throught the set of coins as we reduce the amount to be give out 
            count = change / coins[i];
            // This saves the number of times we have used some value of coins and saves it 
            number = number + count;
            // This keeps track of the remaining change to be given to the customer
            change = change - count * coins[i];
        }
    }
    printf("%i\n", number);
}

