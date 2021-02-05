import cs50  # importing the get_float function from cs50 libraries

# Defining our main function for the program


def main():
    # Setting the condition that the user must meet if not it will keep asking until right input is given
    while True:
        # Getting input from the user
        dollar = cs50.get_float("Change Owed: ")
    # The input should be a non-negative integer
        if dollar >= 0:
            break

    # Changing the dollar input into cents
    change = int(dollar * 100)

    # Calling the function to calculate the amount
    calc(change)

# defining our function to calculate the least number of coins to be given


def calc(n):
    number = 0
    coins = [25, 10, 5, 1]
    for coin in coins:
        if coin <= n:
            count = n // coin
            number += count
            n = n - count * coin
    print(f"{number}\n", end="")


# Call back main
if __name__ == '__main__':
    main()
