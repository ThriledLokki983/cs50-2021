import csv

with open("file.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        print(row[0])
