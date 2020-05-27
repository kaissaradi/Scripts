-- Find the first_name, last_name and total_combined_film_length of Sci-Fi films for every actor.
-- That is the result should list the names of all of the actors(even if an actor has not been in any Sci-Fi films) and the total length of Sci-Fi films they have been in.
-- Look at the category table to figure out how to filter data for Sci-Fi films.
-- Order your results by the actor_id in descending order.
-- Put query for Q3 here


select actor.actor_id, actor.first_name, actor.last_name, sum.total_combined_film_length
from actor left join( 
select actor.actor_id, SUM(film.length) as total_combined_film_length
from actor left join film_actor
on actor.actor_id = film_actor.actor_id left join film
on film_actor.film_id = film.film_id left join film_category
on film.film_id = film_category.film_id left join category
on film_category.category_id = category.category_id
where category.category_id = '14'
group by actor.actor_id) as sum
on actor.actor_id = sum.actor_id
order by actor.actor_id desc;
