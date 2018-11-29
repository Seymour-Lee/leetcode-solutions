# Write your MySQL query statement below
select a.Id, if(isnull(a.p_id), 'Root', if(a.id in (select p_id from tree), 'Inner', 'Leaf')) Type
from tree a
order by a.Id