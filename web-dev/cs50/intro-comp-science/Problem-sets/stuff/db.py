import csv
import cs50

#create a database by opening and closing it 
open(f"show1.db", "w").close()
data = cs50.SQL("sqlite:///show1.db")
