# [level 2] [3차] 파일명 정렬 - 17686 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17686) 

### 성능 요약

메모리: 4.2 MB, 시간: 1.15 ms

### 구분

코딩테스트 연습 > 2018 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

<br/><br/>
# 📊 노트
## 1. stoi(),to_string() 이용하기
C++을 무시하지마라.... Integer.toString() 역할을 하는 to_string()이 C++에도 있다. (<string> 헤더파일에 존재)<br/>
괜히 trim하지 말고 stoi() (역시 <string>에 존재), to_string 이용
## 2. transform을 이용해서 uppercase, lowercase 처리
<algorithm>에 정의된 transform 함수로 ```transform(str.begin(),str.end(),덮어쓰기 시작 위치,::toupper)```하여 str을 uppercase로 변환<br/>
이 때 원본이 덮어쓰이므로, 인자로 넘어온 문자열을 복사해서 사용하기!
## 3. substr엔 두 개의 인자를
```str.substr(시작 문자열 위치, 부분 문자열의 길이)```<br/>
인수로 시작 인덱스만 전달한다면 해당 인덱스 ~ 문자열 마지막까지 반환
## 4. 주의해야 할 점
tail 부분이 존재하지 않는 문자열들이 있을 수 있었음
때문에 tailindex이 초기화되지 않은 상태에서 substr에서 tailindex를 이용해서 오류가 발생 (segment fault)

