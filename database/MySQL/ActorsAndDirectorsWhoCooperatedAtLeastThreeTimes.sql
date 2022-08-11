/*
Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.

Return the result table in any order.
*/
SELECT
    DISTINCT ad.actor_id,
    ad.director_id
FROM
    ActorDirector ad
GROUP BY ad.actor_id, ad.director_id
HAVING COUNT(ad.timestamp) >= 3