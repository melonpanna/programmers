# [level 3] 아방가르드 타일링 - 181186 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/181186#qna) 

### 성능 요약

메모리: 4.5 MB, 시간: 2.08 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 05일 23:33:36

## 🖌️노트
### 1.dp
점화식 만들기 굉장히 까다로운 문제...<br/>
기본적으로 생각할 수 있는 건 i-2번째에서,ㄴㄱ모형 두 가지를 붙여서, i-1번째에서 ㅣ 하나 붙여서 i번째 모양을 만들 수 있음<br/>
+ i-3번째에서 모양 5가지 중 하나를 붙여서 만들 수 있으므로<br/>
```
dp[i]=dp[i-2]*2+dp[i-1]+dp[i-3]*5
```
가 된다<br/>
여기에 3n,3n+1,3n+2마다 붙일 수 있는 새로운 도형이 생긴다!!즉 3칸짜리 모양을 변형해서 6칸짜리,9칸짜리... 새로운 모양을 만들 수 있고<br/>
4칸짜리를 변형해서 7칸짜리,10칸짜리,13,16...을 만들 수 있다!<br/>
그러므로 i보다 3k,3k+1,3k+2(k=1,2,3...)만큼 작은 수에서 분기하는 경우를 모두 생각해줘야 함!<br/>
이걸 while문으로 k를 점점 늘리며 계산하면 시간초과가 나므로, 누적합(일종의 메모이제이션)을 이용해야 한다
### 2.오버플로우 주의
복합대입연산자(+=,*= 등)를 사용하는 과정에서 더하는 수가 int여도, 변수에 더하는 과정에서 오버플로우가 발생할 수 있기 때문에<br/>
a+=b%MOD 대신, a=(a+b)%MOD로 바꿔야 한다! 이때 괄호 안에 a까지 넣어서 한꺼번에 MOD로 나눈 나머지를 구해야 함<br/>
그리고 맨 앞에 (long long)으로 캐스팅 해주기
### 3.누적합
특이하게 3 단위로 누적합을 만들어주면 됨<br/>
3k끼리, 3k+1끼리, 3k+2끼리만 dp[i]를 누적하는 sum을 만들어서 while문을 돌지 않고 한 번에 dp[i]에 더해주면 됨<br/>
sum[3k]=dp[3k]+sum[3k-3]인 것!
