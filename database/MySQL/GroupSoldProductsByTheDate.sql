# query for sell_date
# group all items in query by the sell_date (to find all items sold on the same day)
# Order all items by sell_date
# Find and count the number  of  distinct products (sold on the same day)
# Group all the products sold on the same day and display it
SELECT
    sell_date,
    COUNT(DISTINCT(product)) AS num_sold,
    GROUP_CONCAT(DISTINCT(product)) AS products
FROM
    Activities
GROUP BY sell_date ORDER BY sell_date;