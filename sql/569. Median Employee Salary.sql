# Write your MySQL query statement below
select t1.Id as Id, t1.Company, t1.Salary
from Employee as t1 inner join Employee as t2
on t1.Company = t2.Company
group by t1.Id
having abs(sum(CASE when t2.Salary<t1.Salary then 1
                  when t2.Salary>t1.Salary then -1
                  when t2.Salary=t1.Salary and t2.Id<t1.Id then 1
                  when t2.Salary=t1.Salary and t2.Id>t1.Id then -1
                  else 0 end)) <= 1
order by t1.Company, t1.Salary, t1.Id