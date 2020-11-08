import csv
import sys

def main():
    strings = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]

    with open ("dna/sequences/1.txt", "r") as dna_seq:
        fd = dna_seq.read().replace("\r\n","").replace("\n","")

    output = {}
    for string in strings:
        output[string] = {'count':0, 'longest':0, 'longest_idx':-1}
        idx = 0
        while (idx:=fd.find(string, idx)) > -1:
            prevIdx = idx
            currCount = 0
            while (idx := fd.find(string, idx, idx+len(string))) > -1:
                output[string]['count'] += 1
                currCount += 1
                idx += len(string)
            idx = prevIdx + (currCount * len(string))

            if currCount > output[string]['longest']:
                output[string]['longest'] = currCount
                output[string]['longest_idx'] = prevIdx

    [print(f"{key:<10s} was seen {val['count']} times, "
           f"and its longest match was {val['longest']} at index {val['longest_idx']}"
           ) for key, val in output.items()]

if __name__ =="__main__":
    main()