# Write your MySQL query statement below
select Ee.name
from Employee as Ee
inner join (
select managerId, COUNT(e.managerId) as mi
from Employee as e
group by e.managerId
HAVING mi >= 5 ) as t on t.managerId = Ee.Id