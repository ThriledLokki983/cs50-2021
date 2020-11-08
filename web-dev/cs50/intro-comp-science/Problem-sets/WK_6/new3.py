def main():
    with open ('dna/sequences/1.txt', 'rt') as fp:
        sequences = [seq.strip() for seq in fp]


    substrings = []
    s = 0
    seq = sequences[0]
    max_repetions = {s: 0 for k in ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]}
    higest_match_idx = {s: 0 for k in ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]}
    for idx, c in enumerate(seq):
        for substr, max_rep in max_repetions.items():
            if higest_match_idx[substr] > idx:
                continue
            match_length = 0
            while seq[idx:idx+len(substr)] == substr:
                match_length += 1
                idx += len(substr)
                higest_match_idx[substr] = idx
            if match_length > max_rep:
                substrings[substr] = match_length

if __name__ == "__main__":
    main()