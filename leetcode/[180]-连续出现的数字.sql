# Write your MySQL query statement below
select distinct l1.num consecutivenums
from logs l1 join logs l2
on l1.num = l2.num
group by l1.id
        having sum(l1.id - l2.id between 0 and 2) > 2