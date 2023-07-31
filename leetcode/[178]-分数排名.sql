# Write your MySQL query statement below
select s1.Score, count(distinct(s2.Score)) `Rank`
from Scores s1, Scores s2
where s1.Score<=s2.Score
group by s1.Id
order by `Rank`;