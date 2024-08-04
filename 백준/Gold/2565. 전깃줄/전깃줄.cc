#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int longest[505];
	vector<pair<int, int>> v;
	int n,a,b;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) {
		longest[i] = 1;
		for (int j = 0;j < i;j++) {
			if (v[j].first < v[i].first && v[j].second < v[i].second) {
				longest[i] = max(longest[i], longest[j] + 1);
			}
		}
	}
	int ans = longest[0];
	for (int i = 1;i < n;i++)if (longest[i] > ans)ans = longest[i];
	cout << n-ans;
	return 0;
}