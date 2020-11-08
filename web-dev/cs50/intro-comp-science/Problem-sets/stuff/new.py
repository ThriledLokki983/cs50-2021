import csv
import sys
from sys import argv
import re



def main():
    with open('WK_6/dna/databases/large.csv', newline='') as csvfile:
        file = csv.DictReader(csvfile)
        for row in file:
            #print(list(row.keys())[1:])
            print (list(row.values())[1:])
            #print(list(row.items())[1:])
            #file = (row['name'], row['AGATC'], row['TTTTTTCT'], row['AATG'], row['TCTAG'], row['GATA'], row['TATC'], row['GAAA'], row['TCTG'])
        #print(file)
        print([int(v) for v in list(row.values())[1:]])







if __name__ == "__main__":
    main()