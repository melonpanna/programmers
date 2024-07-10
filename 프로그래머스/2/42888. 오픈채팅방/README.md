# [level 2] 오픈채팅방 - 42888 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42888) 

### 성능 요약

메모리: 39 MB, 시간: 129.07 ms

### 구분

코딩테스트 연습 > 2019 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 07월 10일 18:02:30

## 🐈 노트
### 1. 문자열 split
드디어 C++에서도 split을 할 수 있는 함수를 .. 원래 있었지만 내가 배웠다 <br/>
헤더에는 `#include <sstream>`을 추가하면 됨<br/>
사용법은<br/>
```
istringstream ss("With this treasure I summon");

string stringBuffer; //문자열 자를 때, 자른 문자열 조각 임시저장하는 변수
vector<string> v; //문자열 조각들 저장할 벡터

while(getline(ss,stringBuffer,' ')){
        //공백(' ')을 기준으로 자름
        v.push_back(stringBuffer);
}

//result: v: ['With','this','treasure','I','summon']
```
