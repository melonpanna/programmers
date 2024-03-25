# [level 3] [카카오 인턴] 보석 쇼핑 - 67258 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/67258) 

### 성능 요약

메모리: 13 MB, 시간: 77.95 ms

### 구분

코딩테스트 연습 > 2020 카카오 인턴십

### 채점결과

정확성: 33.3<br/>효율성: 66.7<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 25일 13:52:00

## 🪼노트
### 투포인터를 이용한 부분합 구하는 문제
여기서 다음에 풀 때 개선할 점-[start,end) (혹은 [left,right)) 의 부분합을 구해서 end==n일 때 반복문 종료되게 짜면 됨<br/>
그리고 start를 조건에 따라 +1 해주는 대신, start가 증가하는 반복문 안에 while문을 배치시켜 코드를 간결하게 만들 수 있음<br/>
ex)
```
for start in range(n):
   while sum < m and end < n:
       sum += data[end]
        end ++
    
    if sum == m:
       count ++
    sum -= data[start]
```
