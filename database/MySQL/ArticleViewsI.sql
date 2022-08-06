/*
Write an SQL query to find all the authors that viewed at least one of their own articles.

Return the result table sorted by id in ascending order.

The query result format is in the following example.
*/
SELECT
    v.author_id as id
FROM
    Views as v
WHERE
    v.author_id = v.viewer_id
GROUP BY v.author_id
ORDER BY v.author_id ASC