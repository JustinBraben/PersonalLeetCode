/*
Write an SQL query to calculate the total time in minutes spent by each employee on each day at the office. 
Note that within one day, an employee can enter and leave more than once. 
The time spent in the office for a single entry is out_time - in_time.

Return the result table in any order.
*/
SELECT
    DISTINCT(event_day) as day,
    emp_id,
    SUM(out_time - in_time) as total_time
FROM
    Employees
GROUP BY emp_id, event_day