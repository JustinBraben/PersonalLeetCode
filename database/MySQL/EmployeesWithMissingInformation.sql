/*
Uses a UNION between Table Salaries and Employees
You can use UNION because both  queries have the same
number of  columns (only employee_id)
*/
SELECT 
    employee_id
FROM
    Employees
WHERE
    employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION
SELECT
    employee_id
FROM
    Salaries
WHERE
    employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY
    employee_id