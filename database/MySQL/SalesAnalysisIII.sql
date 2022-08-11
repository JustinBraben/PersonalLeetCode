/*
Write an SQL query that reports the products that were only sold in the first quarter of 2019.

That is, between 2019-01-01 and 2019-03-31 inclusive.

Return the result table in any order.
*/
SELECT
    s.product_id as product_id,
    p.product_name
FROM
    Product p, Sales s
WHERE
    p.product_id = s.product_id
GROUP BY s.product_id, p.product_name
HAVING min(s.sale_date) >= '2019-01-01' AND max(s.sale_date) <= '2019-03-31'