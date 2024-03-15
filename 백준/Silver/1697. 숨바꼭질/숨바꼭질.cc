#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_N 100001
using namespace std;
int shortest[MAX_N];
int n, k;
void bfs(int num) {
	int cnt = 0;
	shortest[num] = 0;
	queue<int> q;
	q.push(num);
	while (true) {
		int current = q.front();
		q.pop();
		//먼저 큐에 넣는 게 임자
		if (current - 1 >= 0 && shortest[current - 1] == -1) {
			shortest[current - 1] = shortest[current] + 1;
			if (current - 1 == k)return;
			q.push(current - 1);
		}
		if (current +1 <= 100000 && shortest[current +1] == -1) {
			shortest[current +1] = shortest[current] + 1;
			if (current +1== k)return;
			q.push(current +1);
		}
		if (current!=0&&2*current <= 100000 && shortest[2*current] == -1) {
			shortest[2*current] = shortest[current] + 1;
			if (2*current == k)return;
			q.push(2*current);
		}
	}
}
int main() {
	memset(shortest, -1, sizeof(shortest));
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	else bfs(n);
	cout << shortest[k];
	return 0;
}