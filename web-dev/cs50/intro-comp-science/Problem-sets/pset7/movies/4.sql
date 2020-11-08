SELECT COUNT(*)
FROM movies
WHERE id IN (
SELECT movie_id
FROM ratings
WHERE rating is 10.0);