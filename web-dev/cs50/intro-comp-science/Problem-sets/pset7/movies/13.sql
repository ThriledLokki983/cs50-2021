SELECT name FROM people WHERE id is "844752";


-- SELECT stars.movie_id, stars.person_id, costar.person_id AS costar_id, name FROM stars
-- INNER JOIN stars AS costar ON stars.movie_id=costar.movie_id INNER JOIN people ON people.id=costar_id GROUP BY stars.movie_id LIMIT 10;
