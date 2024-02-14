# [level 2] [1차] 캐시 - 17680 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17680?language=cpp) 

### 성능 요약

메모리: 4.16 MB, 시간: 0.28 ms

### 구분

코딩테스트 연습 > 2018 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0
<br/><br/><br/><br/>
# 😎 노트

## 1. 자료구조 선택
문제에서 요구한 건 LRU지만 순간 LFU(Least Frequently Used)로 혼동해서, 참조 횟수를 저장하려 map을 쓰려 했으나 이내 queue를 선택함
하지만 queue는 iterator을 사용하여 참조 및 삭제가 할 수 없기 때문에, vector을 사용함.
어차피 v.begin()을 삭제하고, 벡터 중간에 자료를 삽입하는 것이 아닌, 항상 맨 뒤에 자료를 삽입하는 것이라 v.push_back()을 이용하면 돼서 상관 없었음.
## 2. v.erase의 잘못된 사용
v.erase에는 iterator을 전달해야 하는데, 자꾸 it-v.begin()을 인자로 넘겨서 컴파일 에러가 났음.
반복자끼리 뺄셈 연산을 하면 index 값이 반환됨 ex) it-v.begin()이 5만큼 차이가 나는 반복자라면 5가 반환됨
## 3. C++ transform
uppercase 함수처럼 C++에서도 문자열의 모든 char을 대문자/소문자로 변형할 수 있음.
헤더는 <algorithm>임.<br/>
//소문자화 - 세 번째 parameter은 덮어쓰기를 시작할 장소(iterator)<br/>
transform(str.begin(), str.end(), str.begin(), ::tolower);<br/>
//대문자화<br/>
transform(str.begin(), str.end(), str.begin(), ::toupperr);
## 4. 항상 주의해야 할 점
자료구조가 비어 있을 때 원소를 참조하거나 삭제하는 연산이 실행되어 segment fault를 일으킬 수 있으므로 주의!
