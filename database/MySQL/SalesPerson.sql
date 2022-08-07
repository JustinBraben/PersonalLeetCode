/*
Uses IN operator with nested queries
to find Salespeople that never made orders
with company 'RED'
*/
SELECT s.name FROM SalesPerson s WHERE s.sales_id NOT IN 
        (SELECT o.sales_id FROM Orders o WHERE o.com_id IN
            (SELECT c.com_id FROM  Company c WHERE c.name='RED'
            )
        )