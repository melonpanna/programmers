# [level 2] 양궁대회 - 92342 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/92342) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.05 ms

### 구분

코딩테스트 연습 > 2022 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

## 💘 노트
### 1. 시간복잡도 단축한 접근
문제에서 화살을 과녁에 맞히는 경우의 수는 11H10으로 20C10과 같은 숫자인데, 이게 가늠이 되지 않아 시간 단축을 고려함<br/>
근데 저 경우의 수도 184756으로, 완전탐색이 가능하다고 한다<br/>
하여튼! 더 쉽게 푸는 방법은 i점을 따낼 것인지, 버릴 것인지를 조합으로 계산하고,<br/>
만약 가진 화살의 개수를 초과하면 함수를 종료하고, 따낼 수 있는 점수를 따내고도 화살이 남으면 0점 화살에 남은 화살들을 몰빵해 준다<br/>
가장 낮은 점수를 더 많이 맞힌 경우가 최종 답이 되기 때문!<br/>
그 다음으로 낮은, 그 다음으로 낮은.. 과녁에 분산할 필요 없이 몰빵해야 함. 왜냐하면 이미 쳐낼 점수였으면, 쳐낼 만큼의 최소한의 화살이 꽂혀 있을 거고, 그 경우에는 제일 낮은 점수에 몰빵하는 게 정답에 근접한 경우기 때문
### 2. 주의할 점
재귀 호출 시마다 vector을 새로 생성하는 것이 (근데 생각해보니 10개만 만들어서 가지고 다니면 되나?) 메모리 측면에서 부담스러울 것이라고 생각해서<br/>
전역변수 answer에다가 각 경우마다의 화살 개수를 저장했는데, 이 경우 그 함수 스택을 종료할 때 answer도 원상복구한 후 종료해야 함<br/>
이때 남은 화살을 0점 과녁에 몰빵했을 경우도 원상복구한 후 종료해야 함!
