# Write your MySQL query statement below
select q.query_name,ROUND(AVG((q.rating)/(q.position)),2) as quality,
ROUND((AVG((IF(q.rating<3,1,0))))*100,2) as poor_query_percentage
from Queries q where query_name is not NULL
group by q.query_name;