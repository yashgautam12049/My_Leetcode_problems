# Write your MySQL query statement below
select f.unique_id,e.name from Employees e left join EmployeeUNI f on e.id=f.id;