from sys import argv

def sub_string_count(text, substr):
#def main(substr):
    str_seq = []
    text = argv[1]
    with open ('argv[1]', 'r') as dna_seq:
        for seq in dna_seq:
            str_seq.append(seq.rstrip('\n'))

    str = str_seq[0]
    results = []
# A list with keys (sub strings that I want to search for in the txt file // But this does not work - Error msg: TypeError: list indices must be integers or slices, not str)
    substr1 = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    for substr in substr1:
        results.append(sub_string_count(str, substr))
        total_sum = sum(results)
    print(total_sum)

if __name__ == 'sub_string_count':
    sub_string_count(text)

#main()