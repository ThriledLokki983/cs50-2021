from sys import argv
import csv


def main():
    while True:
        if len(argv) != 3:
            print("Usage: csv file -->> txt file")
            exit(1)
        else:
            with open(argv[1], "r") as csvfile:
                file = csv.DictReader(csvfile)
                for row in file:
                    main = ([int(v) for v in list(row.values())[1:]])
        print(main)

        mylist = []
        with open(argv[2], "r") as csvfile1:
            file1 = csvfile1.read()
        for seq in file1:
            mylist = []
            mylist.append(file1.rstrip('\n'))
            substr1 = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
            str_seq1 = []
            seq = []
            for substr in substr1:
                str_seq1.append(substr)
            #for row in file1:
            print(file1)
        index = 0
        prev = 0
        str = mylist[0]
        substr = "AATG"
        while index < len(str):
            index = str.find(substr, index)
            if index == -1:
                break
            prev = index + len(substr)
            index += len(substr)
        seq.append(len(substr))
        print(seq)
        exit(0)


if __name__=="__main__":
    main()