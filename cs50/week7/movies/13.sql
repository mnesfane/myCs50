SELECT DISTINCT people.name FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE movies.id IN (SELECT movie_id FROM stars JOIN people
ON stars.person_id = people.id AND people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name <> 'Kevin Bacon';