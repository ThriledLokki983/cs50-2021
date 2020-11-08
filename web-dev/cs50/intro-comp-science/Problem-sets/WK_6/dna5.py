import csv


def main():
    file = []
    seq = []
    with open ("dna/sequences/1.text", 'r') as file1:
        file.append(file1.rstrip('\n'))
        for line in file:
            count = 0
            substr1 = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
            for a in range(len(substr1)):
                for i in range(len(file)):
                    if (file[i : i + len(substr1[a])] == substr1[a] and file[i : i + 2*len(substr1[a])] == substr1[a]):
                        count += 1
                    print(f"count: {count}")


if __name__ == "__main__":
    main()