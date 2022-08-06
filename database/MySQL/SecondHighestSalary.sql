SELECT
    max(salary) as SecondHighestSalary 
FROM
    Employee
WHERE
    salary < (SELECT max(salary) FROM Employee)
ORDER BY salary ASC

/*
#1st method
SELECT 
    max(salary ) as SecondHighestSalary
FROM 
    Employee
WHERE 
    salary<(SELECT max(salary) FROM employee);

#2nd method
SELECT
    DISTINCT(salary) as SecondHighestSalary
FROM
    Employee
ORDER BY 
    salary desc limit 1,1;

#3rd method
SELECT
    salary as SecondHighestSalary
FROM
    Employee e1
WHERE 
    1=(SELECT COUNT(DISTINCT salary)
FROM
    Employee e2
WHERE
    e2.salary > e1.salary);

#4th method
SELECT 
    MAX(salary) as SecondHighestSalary
FROM
    Employee
WHERE
    salary not in (SELECT MAX(salary) FROM employee);
*/