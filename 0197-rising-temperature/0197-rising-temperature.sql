# Write your MySQL query statement below
select w1.id from Weather w1 where w1.temperature>(
    select w2.temperature from Weather w2 where w2.recordDate=DATE_SUB(w1.recordDate,INTERVAL 1 DAY)
);