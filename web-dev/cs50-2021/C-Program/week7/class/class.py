# flat-file database  // A flat file database is a database that stores data in a plain text file //
# You cannot use functions on a flat-file (e.g. csv file)

# relational database // It uses a structure that allows us to identify and access data in relation to another piece of data in the database. Often, data in a relational database is organized into tables

sqlite > .mode csv // change from sql mode into csv mode
sqlite > .import 'shows0.csv' shows // load the csv file and create a table out of it

C = > CREATE[INSERT, ] e.g CREATE TABLE table(column type, ....) CREATE INDEX 'new_name' ON 'table'('column')
SELECT columns FROM table()
R = > READ
U = > UPDATE
D = > DELETE

// Others
AVG
COUNT
DISTINCT
LOWERMAX
MIN
UPPER

// clauses
WHERE
LIKE
ORDER BY
LIMIT
GROUP BY

Types
# BLOB

# INTEGER
smallint
bigint
integer
# NUMERIC
boolean
date
datetime
numeric(scale, precision)
time
timestamp
REAL
real
double precision
# TEXT
char(n)
varchar(n)
text

// column == > NULL & & UNIQUE

// PRIMARY KEY - - A primary key is a field in a table which uniquely identifies each row/record in a database table
// FOREIGN KEY - - A FOREIGN KEY is a field ( or collection of fields) in one table that refers to the PRIMARY KEY in another table

# SQL injection Attacks

# RACE Conditions
