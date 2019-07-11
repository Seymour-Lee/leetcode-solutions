# Write your MySQL query statement below
select actor_id as ACTOR_ID, director_id as DIRECTOR_ID from actorDirector
group by actor_id, director_id
having count(*)>=3