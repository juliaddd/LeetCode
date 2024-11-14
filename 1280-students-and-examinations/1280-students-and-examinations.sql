# Write your MySQL query statement below
select st.student_id, st.student_name, sub.subject_name, count(e.subject_name) as attended_exams
from Students st
cross join Subjects as sub
left join Examinations as e on e.student_id=st.student_id and
e.subject_name = sub.subject_name
group by st.student_id,st.student_name,sub.subject_name
ORDER BY st.student_id, sub.subject_name;