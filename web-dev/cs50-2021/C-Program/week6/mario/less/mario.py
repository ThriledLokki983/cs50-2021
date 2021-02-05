import cs50


def main():
    while True:
        # Get an input from the user (defined as height for the pyramid)
        height = cs50.get_int("Height: ")

        # Set a condition that user's input must fulfill
        if height > 0 and height <= 8:
            break
    # Calling our function that will draw the pyramid
    mario(height)

# Defining a function that draws the pyramid ()


def mario(n):
    for i in range(n):
        print(' ' * (n - i - 1) + '#' * (i + 1))


main()
