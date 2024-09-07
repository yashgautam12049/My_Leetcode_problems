# Write your MySQL query statement below
select p.project_id,IFNULL(ROUND(SUM(e.experience_years)/Count(*),2),0) as average_years
from Project p left join Employee e
on p.employee_id=e.employee_id
group by p.project_id;