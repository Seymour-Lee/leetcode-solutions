# Write your MySQL query statement below
select f1.follower, count(distinct f2.follower) as num
from follow f1 join follow f2 on f1.follower = f2.followee
group by f1.follower