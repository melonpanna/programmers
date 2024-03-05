# [level 2] H-Index - 42747 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42747#qna) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 정렬

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

# 노트
### 1. 문제 이해
첫 번째 접근-무의식중에 이분 탐색 범위를, citations을 오름차순 정렬하여 그 안에서 인용수를 이분 탐색 함<br/>
하지만 반례)[1,16,17]에서 H-index는 1이 아닌 2이다.<br/>
조건을 만족하는 최댓값을 구하는 것이므로 H-index는 citations 내의 값이 아닐 수 있음
