select date_format(sales_date,'%Y-%m-%d') as SALES_DATE, product_id, user_id, sales_amount
from online_sale
where sales_date between '2022-03-01' and '2022-03-31'
union
select date_format(sales_date,'%Y-%m-%d') as SALES_DATE, product_id, NULL as user_id, sales_amount
from offline_sale
where sales_date between '2022-03-01' and '2022-03-31'
order by sales_date asc, product_id asc, user_id asc;
;