# Write your MySQL query statement below
select distinct a.Num as ConsecutiveNums
from Logs a join Logs b join Logs c
where a.Num = b.Num and b.Num = c.Num and b.Id-a.Id = 1 and c.Id-b.Id = 1