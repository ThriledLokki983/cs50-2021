import csv

with open("shows0.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["primaryTitle"])
