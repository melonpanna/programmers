SELECT mp.member_name, r.review_text, date_format(r.review_date,'%Y-%m-%d') as 'REVIEW_DATE'
from member_profile mp join rest_review r
on mp.member_id=r.member_id
where mp.member_id = (select member_id from rest_review
                  group by member_id
                  order by count(*) desc limit 1)
order by r.review_date, r.review_text;