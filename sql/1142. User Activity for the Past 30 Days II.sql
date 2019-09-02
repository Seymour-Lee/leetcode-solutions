# Write your MySQL query statement below
SELECT IFNULL(ROUND(count(DISTINCT user_id, session_id)/COUNT(DISTINCT user_id), 2), 0.00) AS average_sessions_per_user
FROM activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'