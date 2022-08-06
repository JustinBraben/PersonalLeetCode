/*
Find  Customers that visited without making a transaction
there would be an entry for them in the Visits table
but there would be no related entry in  the Transactions table
Group by  lets you use the aggregate function COUNT to 
count the number of rows with the same customer_id (count number of visits)
*/
SELECT
    v.customer_id,
    COUNT(v.customer_id) AS count_no_trans
FROM
    Visits AS v
WHERE
    v.visit_id NOT IN (SELECT t.visit_id FROM Transactions AS t)
GROUP BY v.customer_id
ORDER BY COUNT(v.customer_id)