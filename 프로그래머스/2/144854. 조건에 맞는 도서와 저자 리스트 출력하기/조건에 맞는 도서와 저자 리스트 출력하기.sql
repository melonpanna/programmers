SELECT b.book_id, a.author_name, date_format(b.published_date,'%Y-%m-%d') PUBLISHED_DATE
from book b, author a
where b.category = '경제' and b.author_id = a.author_id
order by b.published_date asc;