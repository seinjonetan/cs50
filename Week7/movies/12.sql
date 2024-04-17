SELECT title FROM movies, stars, people
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND name IN ('Helena Bonham Carter' , 'Johnny Depp')
    GROUP BY title
    HAVING COUNT(*) > 1;