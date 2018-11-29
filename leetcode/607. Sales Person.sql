# Write your MySQL query statement below
select s.name from salesperson s where s.sales_id not in (
    select o.sales_id from orders o join company c on o.com_id = c.com_id where c.name = 'RED'
)