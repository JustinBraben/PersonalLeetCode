/*
Write an SQL query to report the name and balance of users with a balance higher than 10000. 
The balance of an account is equal to the sum of the amounts of all transactions involving that account.

Return the result table in any order.
*/
SELECT
    u.name,
    SUM(t.amount) as balance
FROM
    Users u LEFT JOIN Transactions t
    ON u.account = t.account
GROUP BY t.account
HAVING SUM(t.amount) > 10000