#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 910
using namespace std;
int n, k, f, cnt = 0;
bool matrix[MAX_SIZE][MAX_SIZE] = { false, };
bool found = false;
vector<int> ans;
vector<int> friend_num;
void dfs(int index, int cnt) {
	if (found)return;
	if (cnt >= k) {
		for (auto e : ans)cout << e << '\n';
		found = true;
		return;
	}
	bool fail;
	for (int i = index + 1; i <= n; i++) {
		fail = false;
		if (friend_num[i] >= k - 1) {
			for (auto e : ans) {
				if (!matrix[e][i]) { 
					fail = true; 
					break;
				}
			}
			if (!fail) {
				ans.push_back(i);
				dfs(i, cnt + 1);
				ans.pop_back();
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n >> f;
	friend_num.resize(n + 1, 0);
	int temp1, temp2;
	for (int i = 0; i < f; i++) {
		cin >> temp1 >> temp2;
		matrix[temp1][temp2] = true;
		matrix[temp2][temp1] = true;
		friend_num[temp1]++;
		friend_num[temp2]++;
	}
	for (int i = 1; i <= n - k+1; i++) {
		if (friend_num[i] >= k - 1) {
			ans.push_back(i);
			dfs(i, 1);
			ans.pop_back();
		}
	}
	if (!found)cout << -1;
	return 0;
}