SELECT t1.title, t1.board_id, t2.reply_id, t2.writer_id, t2.contents, date_format(t2.created_date,'%Y-%m-%d') as CREATED_DATE
from used_goods_board t1 join used_goods_reply t2
on t1.board_id=t2.board_id
where date(t1.created_date) between '2022-10-01' and '2022-10-31'
order by t2.created_date asc, t1.title asc;