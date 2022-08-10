/*
Write an SQL query to report the first login date for each player.

Return the result table in any order.
*/
SELECT
    DISTINCT(player_id),
    MIN(event_date) as first_login
FROM
 Activity
GROUP BY player_id
