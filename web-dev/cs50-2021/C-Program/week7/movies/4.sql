SELECT COUNT(title)
FROM movies
WHERE id in (SELECT movie_id
FROM ratings
WHERE rating is 10.0);