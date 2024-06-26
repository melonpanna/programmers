# [level 4] 무지의 먹방 라이브 - 42891 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42891) 

### 성능 요약

메모리: 13.6 MB, 시간: 35.57 ms

### 구분

코딩테스트 연습 > 2019 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 42.9<br/>효율성: 57.1<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 11일 15:02:23

## 🍗 노트
### 1. 처음 접근
큐에 넣고 k번 반복문을 돌리며 남은 양을 줄이고, 다 먹었을 경우 큐에서 삭제->효율성 테스트에서 k<=2*10^13이므로 효율성 멸망<br/>
->반복을 줄이기 위해서, 반복문마다 제일 적게 남은 원소를 찾아서(O(n)) (남은 양-1)회 만큼, 음식들을 먹었다고 가정 생각<br/>
즉 (남은 양-1)*n (n:food_times의 길이) 만큼 k에서 차감함<br/>
근데 생각해보니.. (제일 적게 남은 음식의 남은 양)*n>=k일 경우 그냥 food_times[(k-1)%food_times.size()]해도 됐겠다..<br/>
어찌 됐든 이 경우에도 최악의 경우 (ex. 1 2 3 4 5... 처럼 원소간 차이가 거의 없을 경우) O(n\*n)으로 시간초과 (n<=2\*10^5)
### 2. 우선순위 큐를 이용한 풀이
#### 2-1. 우선순위 큐 선언
{남은 양,음식의 번호}를 오름차순으로 정렬하는 우선순위 큐를 선언한다. 이 때 남은 양이 같을 경우, 음식 번호도 오름차순으로 정렬돼야 하므로 cmp를 이용해 정렬 기준을 정의한다
```
auto cmp=[](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first==b.first)return a.second>b.second;
        return a.first>b.first;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
```
#### 2-2. 이 때의 주의점
남은 양이 같은 원소가 여러 개 있을 경우, 남은 양만큼 회전을 반복하는 과정에서 남은 양이 같았던 음식들까지 큐에서 삭제해야 함!<br/>
또한 남은 음식이 없어 -1을 반환하는 종료조건도 적절한 곳에 넣어 segmentation fault를 방지해야 함
#### 2-3. 이 방식의 시간 복잡도
우선순위 큐에 food_times의 원소 삽입: O(n*logn)<br/>
k가 조건을 충족할 때까지 우선순위 큐의 원소 삭제: O(n)<br/>
원소 삭제 종료 후, 남은 음식들의 번호를 오름차순 정렬하여 k번째 출력: O(nlogn)<br/>
전체 시간복잡도: O(nlogn)
