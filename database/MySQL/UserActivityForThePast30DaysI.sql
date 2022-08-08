/*
Query gets dates for activity and aggregates the
number of distinct users that day.
Uses HAVING statement to look for dates within
and 30 days of 2019-07-27 and including 2019-07-27
*/
SELECT
    activity_date as day,
    count(DISTINCT(user_id)) as active_users
FROM
    Activity
GROUP BY
    activity_date
HAVING
    (activity_date > "2019-06-27" AND activity_date <= "2019-07-27")