# [level unrated] 가장 많이 받은 선물 - 258712 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/258712) 

### 성능 요약

메모리: 3.92 MB, 시간: 1.45 ms

### 구분

코딩테스트 연습 > 2024 KAKAO WINTER INTERNSHIP

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 1월 5일 23:31:29

1. C++ 에서 문자열을 파싱할 때
내가 쓴 방법: str.find(' ')로 공백 문자열의 인덱스를 찾고 그것을 기준으로 substr(시작 인덱스, 문자 개수) <-끝 인덱스가 파라미터가 아님에 주의
다른 방법: <sstream>을 헤더에 추가하여
stringstream(parse(문자열)); 후 parse>>부분문자열1>>부분문자열2;
2. map[key]=value 문법 잘 이용하기! find 쓰면 iterator 처리해야 돼서 번거로움
3. 벡터 내 최댓값 sort 후 첫 번째 이용하지 않고, *max_element(v.begin(),v.end())로 구하기
4. 
