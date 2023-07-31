# Write your MySQL query statement below
select (
        select Salary from Employee where Salary  < (
select max(Salary) from Employee
)
order by Salary desc
limit 0,1
) as SecondHighestSalary