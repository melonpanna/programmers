SELECT mcdp_cd '진료과코드', count(pt_no) '5월예약건수'
from appointment
where apnt_ymd between '2022-05-01' and '2022-05-31'
# and apnt_cncl_yn = 'N'
group by mcdp_cd
order by count(pt_no) asc, mcdp_cd asc;