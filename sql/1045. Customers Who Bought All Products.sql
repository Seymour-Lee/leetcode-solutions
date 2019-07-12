# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id 
HAVING COUNT(Distinct product_key)=(SELECT COUNT(*) from Product)