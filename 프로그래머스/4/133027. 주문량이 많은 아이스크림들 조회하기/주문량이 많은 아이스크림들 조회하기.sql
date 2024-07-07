SELECT t1.flavor
from first_half t1,
(select flavor,sum(total_order) as 'sum' from july
group by flavor) as newtable
where t1.flavor = newtable.flavor
order by t1.total_order+newtable.sum desc limit 3;