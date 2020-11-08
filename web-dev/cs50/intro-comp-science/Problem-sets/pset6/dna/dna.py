import csv
import sys
from sys import argv
import re



def main():
    with open('databases/large.csv', newline='') as csvfile:
        file = csv.DictReader(csvfile)
        for row in file:
            file = (row['name'], row['AGATC'], row['TTTTTTCT'], row['AATG'], row['TCTAG'], row['GATA'], row['TATC'], row['GAAA'], row['TCTG'])
        #print(file)
    print([int(v) for v in list(row.values())[1:]])

    with open ("sequences/1.txt", 'r') as dna_seq:
        file = dna_seq.read()
        for seq in file:
            mylist = []
            mylist = file
            print(mylist)
            return True
        index = 0
        prev = 0
        str = mylist[0]
        seq = []
        substr = "AGATC"
        while index < len(str):
            index = str.find(substr, index)
            if index == -1:
                break
            prev = index + len(substr)
            index += len(substr)
        seq.append(len(substr))
        print(seq)





if __name__ == "__main__":
    main()