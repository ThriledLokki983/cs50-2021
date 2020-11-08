from cs50 import get_int


## Starting with our main program
def main():
    while True:
        ## Getting an integer input from the user defined as the height
        height = get_int("Height:")
        width = height
        ## Setting a condition that the user's input must fulfill
        if height > 0 and height <= 8:
            break

        ## Calling our function that will draw the pyramid
        for i in range(1, height + 1):
            num_hashes = i
            num_spaces = width - num_hashes

            print(" " * num_spaces, end="")
            print("#" * num_hashes, end="")

            print("  ", end="")

            print("#" * num_hashes)

if __name__ == "__main__":
    main()
