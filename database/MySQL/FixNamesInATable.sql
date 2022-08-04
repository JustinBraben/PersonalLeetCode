/* selecting user_id, concatenation of uppercase(name[1]) and lowercase(name[2:]) and displaying as name */

SELECT
    user_id,
    CONCAT(UPPER(substr(name,1,1)),LOWER(substr(name,2))) as name
FROM
    Users
ORDER BY user_id ASC

/* ordering by user_id in ascending order */