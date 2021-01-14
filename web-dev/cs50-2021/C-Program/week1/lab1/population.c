#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
 // A program to simulate population growth.
int pop_start;
int pop_end;
int count = 0; 
int new_pop;
int new_number = 0;

// Prompt user for the Start size of the population // ensure that the users input is at least 9
do
{
 pop_start = get_int("Start Size: ");
} while (pop_start < 9);


// Prompt user again for the end size of the population // ensure that the users input is greater / == to the start pop size
do
{
 pop_end = get_int("End Size: ");
} while (pop_end <= pop_start);

// Calculate how many years require for the change in population size
// n = n + (n/3) - (n/4) ==> new population

for (int i = 0; i <= pop_start; i++)  
{
 new_pop = pop_start + ((pop_start/3) - (pop_start/4));
 if (new_pop <= pop_end) 
 {
  count++;
  pop_start = new_pop;
 }
}
printf("Years: %i\n", count);


/* 
*/

// Print out the number of years it will take for the start size to get to the end size.

 return 0;
}