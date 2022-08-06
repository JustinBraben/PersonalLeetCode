/*
Tree nodes in SQL traversed by Union
and IN() statements
*/
SELECT
    id,
    'Root' as type
FROM
    Tree
WHERE
    p_id IS NULL
UNION
SELECT
    id,
    'Leaf' as type
FROM
    Tree
WHERE
    p_id IS NOT NULL AND id NOT IN (SELECT p_id from Tree WHERE p_id IS NOT NULL)
UNION
SELECT
    id,
    'Inner' as type
FROM
    Tree
WHERE
    p_id IS NOT NULL and id IN (SELECT p_id FROM Tree)
ORDER BY id ASC