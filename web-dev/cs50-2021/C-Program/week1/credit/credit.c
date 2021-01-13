#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
 long long  card_number = 0;
 int count = 0;

 // Prompt user for an input
do
{
  card_number = get_long_long("Card Number: ");
} while (card_number < 0);

 // Calculate the checksum
long long number = card_number;
while (number > 0)
{
 number = number / 10;
 count++;
}

if ((count != 13) && (count != 15) && (count != 16))
{
 printf("INVALID!\n");
}

int digits[count];

for (int i = 0; i < count; i++)
{
 digits[i] = card_number % 10;
 card_number = card_number / 10;
}

int original_number[count];
for(int i = 1; i < count; i++)
{
 original_number[i] = digits[i];
}

for (int i = 1; i < count; i+=2)
{
 digits[i] = digits[i] * 2;
}

int v = 0;
int temp;

if (count == 13)
{
 for(int i = 0; i < count; i++)
 {
  temp = (digits[i] % 10) + (digits[i]/10 % 10);
  v = v + temp;
 }
 if (original_number[12] == 4 && v % 10 == 0)
 {
  printf("VISA\n");
 }
 else
 {
  printf("INVALID\n");
 }
}

if (count == 15)
{
 for (int i = 0; i < count; i++)
 {
  temp = (digits[i] % 10) + (digits[i]/10 % 10);
  v = v + temp;
 }
 if (original_number[14] == 3 && v % 10 == 0 && (original_number[13] == 4 || original_number[13] == 7))
 {
  printf("AMEX\n");
 }
 else
 {
  printf("INVALID\n");
 }
}

if (count == 16)
{
 for (int i = 0; i < count; i++)
 {
  temp = (digits[i] % 10) + (digits[i] /10 % 10);
  v = v + temp;
 }
 if (original_number[15] == 4 && v == 0)
 {
  printf("VISA\n");
 }
 else if (original_number[15] == 5 && v % 10 == 0 && (original_number[14] == 1 || original_number[14] == 2 || original_number[14] == 3 || original_number[14] == 4 || original_number[14] == 5))
 {
  printf("MASTERCARD\n");
 }
 else
 {
  printf("INVALID\n");
 }
 return 0;
}
 

// printf("%i\n", digits[0]);

 // Check for Card length  & Starting digits

 // Printout AMEX, MASTERCARD, VISA, or INVALID

}