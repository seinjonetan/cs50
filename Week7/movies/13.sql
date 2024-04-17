SELECT DISTINCT name FROM people, stars, movies
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND movie_id IN (SELECT movie_id FROM stars
        WHERE person_id = (SELECT id FROM people
            WHERE name = 'Kevin Bacon'
            AND birth = 1958))
    AND name != 'Kevin Bacon';