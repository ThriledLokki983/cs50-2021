from cs50 import get_float #importing the get_float funtion from cs50 libraries


# Defining our main funtion for the program
def main():
    # Setting the condition that the user must meet if not it will keep asking until right input is given
    while True:
        ## Getting input from the user
        dollar = get_float("Change owed: ")
        # The input should be a non-negative integer
        if dollar >= 0:
            break
    # Changing the dollar input into cents
    change = int(dollar * 100)

    # Calling the function to calculate the amount
    calc(change)

# defining our function to calculate the least number of coins to be given
def calc(change):
    number = 0
    coins = [25, 10, 5, 1]
    for coin in coins:
        if coin <= change:
            count = change // coin
            number += count
            change = change - count * coin
    print(f"{number}\n", end=" ")

    # Calling back main
main()
