# Write your MySQL query statement below
select coalesce(s.user_id, 0) as user_id, coalesce(c.confirmation_rate, 0) as confirmation_rate
from Signups as s
left join (select user_id, round(COALESCE(sum(action = 'confirmed')/ count(action),0), 2) as confirmation_rate
from Confirmations
group by user_id)
as c on c.user_id= s.user_id