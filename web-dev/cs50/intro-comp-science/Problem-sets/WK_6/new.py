import csv


def main():
    with open('dna/databases/small.csv', newline='') as file1:
        file2 = csv.DictReader(file1)
        data = dict()
        for rows in file2:
            print([int(v) for v in list(rows.values())[1:]])


    strs = ()
    for header in file2.fieldnames:
        if header != "name":
            strs[header] = 0


    with open("dna/sequences/1.txt", "r") as file:
        dna_seq = file.read()
    for key, value in strs.items():
        x = 1
        tmp = 0
        for i in range(0, len(dna_seq), x):
            if dna_seq[i: (i + len(key))] == key:
                x = len(key)
                tmp += 1

                if tmp > strs[key]:
                    strs[key] = key
                else:
                    x = 1

if __name__ == "__main__":
    main()
