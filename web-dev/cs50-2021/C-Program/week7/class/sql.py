import cs50
import csv
import sqlite3

# To normalize data is to eliminate redundancy
# Creating 2 tables SHOWS & GENRES and link them in our database

open("shows.db", "w").close()

db = cs50.SQL("sqlite:///shows.db")

db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE genres (id INTEGER, genre TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE shows_genre (show_id INTEGER, genre_id INTEGER, FOREIGN KEY(show_id) REFERENCES shows(id), FOREIGN KEY(genre_id) REFERENCES genres(id))")
#db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")

with open("shows1.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["primaryTitle"].strip()
        show_id = db.execute("INSERT INTO shows (title) VALUES(?)", title)
        for genre in row["genres"].split(", "):
            genre_id = db.execute(
                "INSERT INTO genres (genre) VALUES(?)", genre)
            db.execute(
                "INSERT INTO shows_genre (show_id, genre_id) VALUES(?, ?)", show_id, genre_id)
