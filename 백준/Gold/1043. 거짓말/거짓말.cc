#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 51
using namespace std;
int root[MAX_N];
int n, m,t,ans=0;
vector<vector<int>> attend;
int truth[MAX_N];
int find_root(int x) {
	if (x == root[x])return x;
	else return root[x] = find_root(root[x]);
}
void union_root(int x, int y) {
	x = find_root(x);
	y = find_root(y);
	if (x == y)return;
	else if (x <= y)root[y] = x;
	else root[x] = y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m>>t;
	attend = vector<vector<int>>(m);
	for (int i = 1; i <= n; i++)root[i] = i;
	int temp;
	for (int i = 0; i < t; i++) {
		cin >> temp;
		truth[i]=temp;//진실
	}
	int repeat;
	for (int i = 0; i < m; i++) {
		cin >> repeat;
		for (int r = 0; r < repeat; r++) {
			cin >> temp;
			attend[i].push_back(temp);
		}
	}
	//같은 파티에 있는 애들끼리 묶어 주기
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < attend[i].size(); j++) {
			union_root(attend[i][j - 1], attend[i][j]);
		}
	}
	//파티 안에 진실 아는 애 있는지 확인
	for (int i = 0; i < m; i++) {
		bool exist = false;
		for (int j = 0; j < attend[i].size(); j++) {
			for (int k = 0; k < t; k++) {
				if (find_root(attend[i][j]) == find_root(truth[k])) {
					exist = true;
					break;
				}
			}
			if (exist)break;
		}
		if (!exist)ans++;
	}
	cout << ans;
	return 0;
}