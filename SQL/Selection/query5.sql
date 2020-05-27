-- Find the film_title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
-- Order the results by film_title in descending order.
--  Warning: this is a tricky one and while the syntax is all things you know, you have to think a bit oustide the box to figure out how to get a table that shows pairs of actors in movies.


-- Put your query for q5 here.
select film.title from film inner join film_actor
on film.film_id = film_actor.film_id left join actor
on film_actor.actor_id = actor.actor_id left join film_actor fa
on film.film_id = fa.film_id left join actor act
on fa.actor_id = act.actor_id
where actor.actor_id = '108'
and act.actor_id = '21'
order by film.title desc;
