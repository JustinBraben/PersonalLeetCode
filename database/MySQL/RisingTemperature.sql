/*
Using inner join in FROM statement
comparing days that are exactly 1 day apart
query will output the id of the recordDate with the higher temperature
of the pair
*/
SELECT
    w1.id as id
FROM
    Weather as w1,
    Weather as w2
WHERE
    w1.temperature > w2.temperature AND to_days(w1.recordDate)=to_days(w2.recordDate)+1