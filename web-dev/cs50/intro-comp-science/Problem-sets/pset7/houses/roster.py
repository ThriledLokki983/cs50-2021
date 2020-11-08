import cs50
import sqlite3
import sys
import csv
from csv import DictReader
from sys import argv


                                ####### SYSTEMATICALLY BUILD SIMPLE CODE.  ##########
                                #######                                    ##########
                                #######                                    ##########
                                #######                                    ##########
                                #####################################################

def main():
    # Check if the command line argument is right
    if len(argv) != 2:
        # Print error if wrong command line argument
        print("Error with command line argument")
        #Exit
        exit(1)
        ##If everything is all right, then we start with the request
    else:
        house = argv[1]
        names = get_info('students.db', house)
        print(f"This is all the information about: {house}")
        #The heart of this code ---Make sure you understand before using this code if downloaded from online---
        for name in names:
            char_name = name
            first, *second, surname, date = char_name
            second = second[0] if second else None
            #Print the results of our request
            print(f"{first}"+ (f" {second} " if second else " ") + f"{surname}" ", born " + f"{ date}")


# Function which will extract the data from the database
def get_info(db, house):
    query_name = "SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last;"
    db = sqlite3.connect(db)
    name = db.cursor()
    name.execute(query_name, [house])
    nam = name.fetchall()
    name.close()
    db.close()
    return nam

if __name__ == "__main__":
    main()


# Gryffindor
# Hufflepuff
# Ravenclaw
# Slytherin


                                ###############################################
                                ###############################################
                                #######                              ##########
                                #######         ENJOY   THIS         ##########
                                #######         TCODE   FROM         ##########
                                #######             GIDEON....       ##########
                                #######                              ##########
                                ###############################################
                                ###############################################








