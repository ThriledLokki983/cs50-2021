import csv
import sys
from sys import argv



def main():
    while True:
        if len(argv) != 2:
            print("Cannot Start DNA sequencing")
            sys.exit(1)
        else:
            with open('databases/large.csv', newline='') as csvfile:
                file = csv.DictReader(csvfile)
                for row in file:
                    file = (row['name'], row['AGATC'], row['TTTTTTCT'], row['AATG'], row['TCTAG'], row['GATA'], row['TATC'], row['GAAA'], row['TCTG'])
                #print(file)
            print([int(v) for v in list(row.values())[1:]])


            with open (argv[1], 'r') as dna_seq:
                text = argv[1]
                seq = dna_seq.read()
                sub_string_count(text, 'AGATC')


def sub_string_count(text, substr):
    seq1 = []
    str = seq[0] #ERROR here, this creates an error due to str_seq1 being an empty list i.e. [], this should be the string you want to search in.
    results = []
    substr1 = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    for substr in substr1:
        results.append(sub_string_count(str, substr))
    total_sum = sum(results) #need to be out of the loop, to generate final result
    print(total_sum)


#for strseq in reader.fieldnames[1:]:
            #maxrunlengths.append(int(row[strseq]))
        #print(f"{row['name']}: {maxrunlengths}")

                #strseq = ([int(v) for v in list(row.values())[1:]])
if __name__ == "__main__":
    main()

                        i = 0
                    count = 0
                    index = 0

                        while index <= length:
                        for substr1[1] in str_seq:
                            index = str.find(substr1[i], index)
                            if index == -1:
                                break
                        count = index + len(substr1[i])
                        index += len(substr1[i])
                        str_seq2.append(len(substr1[i]))



        #import re
#matches = []
#for string in ["AGATC", "TTTTTTCT", "AATG"]:
    #matches.append(re.findall(string, data))

#for strseq in reader.fieldnames[1:]:
            #maxrunlengths.append(int(row[strseq]))
        #print(f"{row['name']}: {maxrunlengths}")

                #strseq = ([int(v) for v in list(row.values())[1:]])