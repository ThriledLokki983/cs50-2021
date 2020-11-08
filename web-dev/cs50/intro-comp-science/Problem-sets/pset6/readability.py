import re
from cs50 import get_string

def main():
    ## Prompt user for the text to be used
    n = get_string("Text: ")
    grade_calc(n)


def grade_calc(n):

    ## Counting each letter in the text
    let = sum(1 for c in n if c.isalpha())

    ## counting the number of words in a text
    word = len(re.findall(r'[^\s,".!?]+', n))
    #print(word)

    ## Counting the number of seactence in the text
    sent = (len(re.split(r'[!?\.]+', n))-1)
    #print(sent)

    ## Calculating the grades after collecting the number of letters words and sentences
    L = let / word * 100;
    S = sent / word * 100;

    ## Calculating the grade index based on the user's input
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if index < 1:
        print("Before Grade 1\n", end="")
    elif index >= 16:
        print("Grade 16+\n", end="")
    else:
        print(f"Grade {index}\n", end="")
main()