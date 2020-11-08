from csv import DictReader
from sys import argv
import cs50
import csv



                                ####### SYSTEMATICALLY BUILD SIMPLEST CODE ##########
                                #######                                    ##########
                                #######                                    ##########
                                #######                                    ##########
                                #####################################################



def main():
    # program should accept the name of a CSV file as a command-line argument & if incorrect print error and exit
    while True:
        if len(argv) != 2:
            print("Error with command_line_arg: ")
            exit(1)
        else:
            # open a database
            open("students.db", "w").close()
            #give it to sqlite3 as a database
            db = cs50.SQL("sqlite:///students.db")
            db.execute("CREATE TABLE students (id INTEGER PRIMARY KEY AUTOINCREMENT, first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255),house VARCHAR(10), birth INTEGER)")
            with open(argv[1], "r") as csvfile:
                file = DictReader(csvfile)
                for row in file:
                    for name in row["name"].split(','):
                        char_name = row["name"].split()
                        first, *second, surname = char_name
                        second = second[0] if second else None
                    #print(char_name)
                        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", first, second, surname, row["house"], row["birth"])
                return True

if __name__== "__main__":
    main()



                                ###############################################
                                ###############################################
                                #######                              ##########
                                #######         ENJOY   THIS         ##########
                                #######         TCODE   FROM         ##########
                                #######             GIDEON....       ##########
                                #######                              ##########
                                ###############################################
                                ###############################################




















###https://wiki.python.org/moin/MacPython
#https://www.python.org/community/sigs/current/pythonmac-sig/

