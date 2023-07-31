CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
        select DISTINCT Salary from Employee 
        order by Salary desc
        limit N,1
  );
END