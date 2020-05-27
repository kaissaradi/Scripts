-- Find the first_name and last_name of all actors who have never been in a Sci-Fi film.
-- Order by the actor_id in ascending order.

-- Put your query for q4 here


select actor.actor_id, actor.first_name, actor.last_name
from actor 
where actor.actor_id not in 
(select actor.actor_id from actor inner join( 
select actor.actor_id, SUM(film.length) as total_combined_film_length
from actor left join film_actor
on actor.actor_id = film_actor.actor_id left join film
on film_actor.film_id = film.film_id left join film_category
on film.film_id = film_category.film_id left join category
on film_category.category_id = category.category_id
where category.category_id = '14'
group by actor.actor_id) as sum
on actor.actor_id = sum.actor_id
order by actor.actor_id asc)
