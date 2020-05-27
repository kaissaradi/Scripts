-- We want to find out how many of each category of film ED CHASE has starred in.

-- So return a table with category_name and the count of the number_of_films that ED was in that category.

-- Your query should return every category even if ED has been in no films in that category

-- Order by the category name in ascending order.

select category.name as category_name, COUNT(actor.actor_id) as numer_of_films
from category left join film_category 
on category.category_id = film_category.category_id left join film_actor
on film_category.film_id = film_actor.film_id left join actor
on film_actor.actor_id = actor.actor_id
and actor.first_name = 'ED' 
and actor.last_name = 'CHASE'
group by category.category_id
order by category.name asc;
