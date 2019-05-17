# Write your MySQL query statement below
select a.Score as Score, count(distinct b.Score) as Rank
from Scores a join Scores b on a.Score <= b.Score
group by a.Id
order by a.Score desc