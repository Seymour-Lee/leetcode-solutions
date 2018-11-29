# Write your MySQL query statement below
SELECT request_at AS "Day", ROUND(((SUM(CASE WHEN LOWER(Status) LIKE "cancelled%" THEN 1.000 ELSE 0 END)) / COUNT(id)), 2) AS "Cancellation Rate" 
FROM trips AS t JOIN users AS u ON t.client_id = u.users_id AND u.banned ='No'
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;