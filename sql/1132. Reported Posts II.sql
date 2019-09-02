# Write your MySQL query statement below

SELECT
ROUND(AVG(sub.rate),2) AS average_daily_percent
FROM
(SELECT
a.action_date, 100.00* COUNT(DISTINCT r.post_id)/COUNT(DISTINCT a.post_id) AS rate
FROM actions a
LEFT JOIN removals r
ON a.post_id = r.post_id
WHERE a.action = 'report' AND a.extra = 'spam'
GROUP BY a.action_date) AS sub