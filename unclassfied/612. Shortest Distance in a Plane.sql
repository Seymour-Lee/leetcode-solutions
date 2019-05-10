# Write your MySQL query statement below
select round(sqrt(min(pow(a.x-b.x, 2) + pow(a.y-b.y, 2))), 2) as shortest
from point_2d a join point_2d b on a.x != b.x or a.y != b.y