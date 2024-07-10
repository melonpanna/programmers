# [level 3] 즐겨찾기가 가장 많은 식당 정보 출력하기 - 131123 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/131123) 

### 성능 요약

메모리: 0.0 MB, 시간: 0.00 ms

### 구분

코딩테스트 연습 > GROUP BY

### 채점결과

Empty

### 제출 일자

2024년 07월 10일 16:22:56

### 문제 설명
<h5>문제</h5>

<p><code>REST_INFO</code> 테이블에서 음식종류별로 즐겨찾기수가 가장 많은 식당의 음식 종류, ID, 식당 이름, 즐겨찾기수를 조회하는 SQL문을 작성해주세요. 이때 결과는 음식 종류를 기준으로 내림차순 정렬해주세요.</p>

<hr>

## 🐈‍⬛ 노트
### 1. GROUP BY 하면 안 되는 이유
```
SELECT food_type, rest_id, rest_name, favorites
from rest_info r
group by food_type
having favorites = (select max(favorites) from rest_info group by food_type having food_type = r.food_type)
order by food_type desc;
```
처음에 이런 모냥으로 답을 제출했는데 오답 처리됨. 그룹화 된 테이블에서 food_type은 이미 대조했으니 favorites만 대조하면 될 거라고 생각했는데
그룹화 후 그 그룹에서 다시 레코드별로 분해해 대조하는 것이 일반적이지 않다는 gpt 의견..!! <br/>
보통 그룹 별 최댓값을 구할 땐 상위 쿼리에서 group by를 쓰는 것이 일반적이지 않다.<br/>
대신 서브 쿼리에서 group by로 최댓값을 구한 후, 상위 쿼리에서 이 값과 일치하는 데이터만 추출함
