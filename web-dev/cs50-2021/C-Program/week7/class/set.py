import csv

primaryTitle = set()

with open("shows0.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        primaryTitle.add(row["primaryTitle"].upper().strip())
    for title in sorted(primaryTitle):
        print(title)
