# [level 4] 주문량이 많은 아이스크림들 조회하기 - 133027 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/133027) 

### 성능 요약

메모리: 0.0 MB, 시간: 0.00 ms

### 구분

코딩테스트 연습 > JOIN

### 채점결과

Empty

### 제출 일자

2024년 07월 07일 17:54:46

### 문제 설명

<p>다음은 아이스크림 가게의 상반기 주문 정보를 담은 <code>FIRST_HALF</code> 테이블과 7월의 아이스크림 주문 정보를 담은 <code>JULY</code> 테이블입니다. <code>FIRST_HALF</code> 테이블 구조는 다음과 같으며, <code>SHIPMENT_ID</code>, <code>FLAVOR</code>, <code>TOTAL_ORDER</code>는 각각 아이스크림 공장에서 아이스크림 가게까지의 출하 번호, 아이스크림 맛, 상반기 아이스크림 총주문량을 나타냅니다. <code>FIRST_HALF</code> 테이블의 기본 키는 <code>FLAVOR</code>입니다. <code>FIRST_HALF</code>테이블의 <code>SHIPMENT_ID</code>는 <code>JULY</code>테이블의 <code>SHIPMENT_ID</code>의 외래 키입니다. </p>
<table class="table">
        <thead><tr>
<th style="text-align: left">NAME</th>
<th style="text-align: left">TYPE</th>
<th>NULLABLE</th>
</tr>
</thead>
        <tbody><tr>
<td style="text-align: left">SHIPMENT_ID</td>
<td style="text-align: left">INT(N)</td>
<td>FALSE</td>
</tr>
<tr>
<td style="text-align: left">FLAVOR</td>
<td style="text-align: left">VARCHAR(N)</td>
<td>FALSE</td>
</tr>
<tr>
<td style="text-align: left">TOTAL_ORDER</td>
<td style="text-align: left">INT(N)</td>
<td>FALSE</td>
</tr>
</tbody>
      </table>
<p><code>JULY</code> 테이블 구조는 다음과 같으며, <code>SHIPMENT_ID</code>, <code>FLAVOR</code>, <code>TOTAL_ORDER</code> 은 각각 아이스크림 공장에서 아이스크림 가게까지의 출하 번호, 아이스크림 맛, 7월 아이스크림 총주문량을 나타냅니다.  <code>JULY</code> 테이블의 기본 키는 <code>SHIPMENT_ID</code>입니다. <code>JULY</code>테이블의 <code>FLAVOR</code>는 <code>FIRST_HALF</code> 테이블의  <code>FLAVOR</code>의 외래 키입니다. 7월에는 아이스크림 주문량이 많아 같은 아이스크림에 대하여 서로 다른 두 공장에서 아이스크림 가게로 출하를 진행하는 경우가 있습니다. 이 경우 같은 맛의 아이스크림이라도 다른 출하 번호를 갖게 됩니다.</p>
<table class="table">
        <thead><tr>
<th style="text-align: left">NAME</th>
<th style="text-align: left">TYPE</th>
<th>NULLABLE</th>
</tr>
</thead>
        <tbody><tr>
<td style="text-align: left">SHIPMENT_ID</td>
<td style="text-align: left">INT(N)</td>
<td>FALSE</td>
</tr>
<tr>
<td style="text-align: left">FLAVOR</td>
<td style="text-align: left">VARCHAR(N)</td>
<td>FALSE</td>
</tr>
<tr>
<td style="text-align: left">TOTAL_ORDER</td>
<td style="text-align: left">INT(N)</td>
<td>FALSE</td>
</tr>
</tbody>
      </table>
<hr>

<h5>문제</h5>

<p>7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 큰 순서대로 상위 3개의 맛을 조회하는 SQL 문을 작성해주세요. </p>

<hr>

## 🍧 노트
### 1. 다른 풀이
july 테이블에서 flavor을 기준으로 그룹화 -> first_half와 이너조인 할 수도 있고, <br/>
july 테이블을 그냥 이너조인 한 후, 조인 한 상태에서 그룹화 할 수도 있음<br/>
```SELECT F.FLAVOR
FROM FIRST_HALF AS F
JOIN JULY AS J
ON F.FLAVOR = J.FLAVOR
GROUP BY F.FLAVOR # 조인 후 그룹화
ORDER BY F.TOTAL_ORDER +SUM(J.TOTAL_ORDER) DESC
LIMIT 3
```
