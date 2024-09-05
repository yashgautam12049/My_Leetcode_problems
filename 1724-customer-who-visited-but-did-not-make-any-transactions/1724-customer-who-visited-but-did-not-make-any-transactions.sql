# Write your MySQL query statement below
select customer_id,count(customer_id) as count_no_trans from Visits v
where v.visit_id NOT IN (select visit_id from Transactions t where t.visit_id)
group by v.customer_id;