# Write your MySQL query statement below
select a.Id as Id
from Weather a join Weather b
where datediff(a.RecordDate, b.RecordDate) = 1 and a.Temperature > b.Temperature