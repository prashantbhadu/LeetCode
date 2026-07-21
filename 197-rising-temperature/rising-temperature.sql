# Write your MySQL query statement below
select  today.id from weather as today
cross join weather as yesterday
where datediff(today.recordDate, yesterday.recordDate)=1 and today.temperature>yesterday.temperature;
