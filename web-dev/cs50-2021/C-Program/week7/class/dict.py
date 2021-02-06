import csv

titles = dict()  # primaryTitle = {}

with open("shows0.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["primaryTitle"].upper().strip()
        if title not in titles:
            titles[title] = 0
        titles[title] += 1


def f(title):
    return titles[title]

# key=lamda titles: titles[title] // this could be put inside the for loop below instead of key=f


for title in sorted(titles, key=f, reverse=True):
    print(title, titles[title])
