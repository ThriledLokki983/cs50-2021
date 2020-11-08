SELECT title
FROM movies
JOIN stars
ON movies.id = movie_id
JOIN people
ON people.id = person_id
WHERE name = 'Johnny Depp'
OR name = 'Helena Bonham Carter'
GROUP BY movies.id
HAVING count(person_id) = 2;
