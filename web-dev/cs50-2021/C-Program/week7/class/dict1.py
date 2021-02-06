import csv

# search for title and the program will return the number of times this title in repeated in this file

title = input("Tile: ").upper().strip()

with open("shows0.csv", "r") as file:
    reader = csv.DictReader(file)
    counter = 0
    for row in reader:
        if row["primaryTitle"].upper().strip() == title:
            counter += 1

    print(counter)
