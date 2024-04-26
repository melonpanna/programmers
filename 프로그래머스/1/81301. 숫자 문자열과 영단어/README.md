# [level 1] 숫자 문자열과 영단어 - 81301 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/81301) 

### 성능 요약

메모리: 4.16 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 2021 카카오 채용연계형 인턴십

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 27일 00:42:27

## 🔎 노트
### 1. 팁: 언어별로 있는 replace 함수를 사용할 것
C++ string의 ```replace```는 시작 인덱스와 길이를 지정하면, 그 부분을 대치할 문자열로 바꿈<br/>
```s.replace(0,3,"gojo");```<br/>
그리고 더 엄청난 함수는..! 문자열에서 대치할 대상을 찾아서 바꿔주는 함수 regex<br/>
```
#include <regex>
s="ihatejogo";
s=regex_replace(s,regex(jogo),"gojo"); //s=="ihategojo"
```
