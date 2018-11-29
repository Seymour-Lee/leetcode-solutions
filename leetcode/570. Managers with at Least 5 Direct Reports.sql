# Write your MySQL query statement below
select a.Name
from Employee a join Employee b on a.Id = b.ManagerId
group by b.ManagerId having count(b.ManagerId) >= 5