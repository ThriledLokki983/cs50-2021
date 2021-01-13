#include <stdio.h>
#include <cs50.h>
#include <math.h>
int LEN = 4;

int main(void)
{
 int coins[4] = {25, 10, 5, 1};
 float dollar;
 int count;
 int number = 0;

 //Get an input from user //Condition that must be fulfilled before program will continue
 do
 {
  dollar = get_float("Change: ");
 } while (dollar < 0);

 // Convert the dollar into coin value
 int change = round(dollar * 100);

 // Create a for-loop to calc the amount to be given without doing it one-by-one 
 for (int i = 0; i < LEN; i++)
 {
  if (coins[i] <= change)
  {
   // Loop through the coins as we reduce the amount to be given out
   count = change / coins[i];

   // Save the number of times a particualar coin has been used in the variable "number"
   number = count + number; 

   // Tracks the change to be given out to the customer
   change = change - count * coins[i];
  }
 }

 // Print out the coin number
 printf("%i\n", number);
 
}