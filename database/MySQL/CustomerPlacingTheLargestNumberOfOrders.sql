/*
Query to find the customer with the largest number of orders
using GROUP BY to aggregate
Order query by descending to have the largest number of orders first
Limit query to 1 entry to get only the customer with most orders
*/
SELECT
    customer_number
FROM
    Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC LIMIT 1