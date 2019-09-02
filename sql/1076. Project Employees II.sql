# Write your MySQL query statement below
SELECT project_id
FROM Project
GROUP BY project_id
HAVING COUNT(DISTINCT employee_id) = 
(SELECT COUNT(DISTINCT employee_id)
 FROM Project
 GROUP BY project_id
 ORDER BY COUNT(DISTINCT employee_id) DESC
 LIMIT 1)