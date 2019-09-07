# Write your MySQL query statement below
select id,
sum(case when month = "Jan" then revenue else null end) as Jan_Revenue,
sum(case when month = "Feb" then revenue else null end) as Feb_Revenue,
sum(case when month = "Mar" then revenue else null end) as Mar_Revenue,
sum(case when month = "Apr" then revenue else null end) as Apr_Revenue,
sum(case when month = "May" then revenue else null end) as May_Revenue,
sum(case when month = "Jun" then revenue else null end) as Jun_Revenue,
sum(case when month = "Jul" then revenue else null end) as Jul_Revenue,
sum(case when month = "Aug" then revenue else null end) as Aug_Revenue,
sum(case when month = "Sep" then revenue else null end) as Sep_Revenue,
sum(case when month = "Oct" then revenue else null end) as Oct_Revenue,
sum(case when month = "Nov" then revenue else null end) as Nov_Revenue,
sum(case when month = "Dec" then revenue else null end) as Dec_Revenue
from Department
group by id
order by id;
