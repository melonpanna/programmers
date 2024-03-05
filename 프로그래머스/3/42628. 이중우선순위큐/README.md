# [level 3] 이중우선순위큐 - 42628 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42628) 

### 성능 요약

메모리: 3.68 MB, 시간: 0.02 ms

### 구분

코딩테스트 연습 > 힙（Heap）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

## 노트
### 1. heap의 메모리 제거
스택 영역에 적재되는 vector와 달리, stl의 priority_queue는 힙 영역에 적재된다.<br/>
따라서 사용하지 않는 priority_queue를 해제하는 것이 필요<br/>
```
priority_queue<int>().swap(pq);
pq = temp;
```
하지만 대부분의 운영체제에서는 힙에 할당된 메모리도 프로그램 종료 시 자동으로 해제된다는데 그러면 웬만해선 메모리 누수 일어나지 않는 것 아닌가.. 고민
### 2. s1.compare(s2)
C++에서도 java의 equals와 같이 두 문자열이 같은지 혹은 대소비교를 실행할 수 있는데,<br/>
java에서와 달리 C++에서는 s1==s2로도 내부 문자열(값)을 비교할 수 있음.
