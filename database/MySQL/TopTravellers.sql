/*
Write an SQL query to report the distance traveled by each user.

Return the result table ordered by travelled_distance in descending order, 
if two or more users traveled the same distance, 
order them by their name in ascending order.
*/
SELECT
    name,
    SUM(if(distance is null,0,distance)) as travelled_distance
FROM
    Users as u LEFT JOIN Rides as r
    ON u.id = r.user_id
GROUP BY user_id
ORDER BY travelled_distance DESC, name ASC