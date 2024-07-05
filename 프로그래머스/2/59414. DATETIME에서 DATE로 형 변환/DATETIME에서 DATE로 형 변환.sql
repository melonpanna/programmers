-- 코드를 입력하세요
SELECT ANIMAL_ID, name, DATE_FORMAT(datetime,'%Y-%m-%d') as 날짜 FROM ANIMAL_INS 
ORDER BY animal_id;