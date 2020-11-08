SELECT movies.title, ratings.rating
FROM movies
INNER JOIN ratings
ON movies.id=ratings.movie_id
WHERE year is 2010
GROUP BY title
ORDER BY rating DESC
