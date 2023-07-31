# Write your MySQL query statement below
select e.Name as Employee
from Employee e
where e.Salary > ( select Salary from Employee e2 where e2.Id = e.ManagerId)