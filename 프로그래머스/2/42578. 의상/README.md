# [level 2] 의상 - 42578 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42578#) 

### 성능 요약

메모리: 4.2 MB, 시간: 0.03 ms

### 구분

코딩테스트 연습 > 해시

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 1월 3일 21:34:47

1. iterator는 map::iterator가 아닌 map<자료형>::iterator 혹은 auto로 선언
2. java의 set처럼, insert 시 이미 key가 존재할 경우 덮어씌워지는 것이 아니라 오류 발생
때문에 erase 후 insert 해야 함
3. m[key]=value 형태로 map에 원소 삽입 가능
4. iterator 사용 시 . 가 아닌 ->로 멤버 참조
