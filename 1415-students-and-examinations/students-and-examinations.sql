
select Students.student_id, Students.student_name,combine.subject_name, count(examinations.student_id) as attended_exams 
from Students cross join Subjects as combine  left join examinations on Students.student_id=examinations.student_id AND combine.subject_name = Examinations.subject_name
group by
Students.student_id,
Students.student_name,
combine.subject_name
order by
Students.student_id,
combine.subject_name;