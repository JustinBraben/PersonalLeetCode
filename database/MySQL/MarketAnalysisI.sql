/*
Write an SQL query to find for each user, 
the join date and the number of orders they made as a buyer in 2019.

Return the result table in any order.
*/
SELECT
    user_id as buyer_id,
    join_date,
    ifnull(COUNT(order_id),0) as orders_in_2019
FROM
    Users LEFT JOIN Orders
    ON user_id = buyer_id
    AND YEAR(order_date) = 2019
GROUP BY user_id;