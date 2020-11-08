from cs50 import get_int


## Starting with our main program
def main():
    while True:
        ## Getting an integer input from the user defined as the height
        height = get_int("Height:")

        ## Setting a condition that the user's input must fulfill
        if height > 0 and height <= 8:
            break

        ## Calling our function that will draw the pyramid
    mario(height)

## Defining a function that draws the pyramid
def mario(height):
    for i in range(height):
        print(' '*(height-i-1)+'#'*(i+1))

main()