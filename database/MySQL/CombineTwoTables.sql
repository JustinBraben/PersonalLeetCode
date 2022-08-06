/*
Left Join to return matching records from 
two different tables
that share personID
*/
SELECT
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM
    Person AS p LEFT JOIN Address AS a
    ON p.personID = a.personID