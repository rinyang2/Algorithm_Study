//topology sorting problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;

int N,M;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N>>M;
	vector<int> v(N+1);
	vector<vector<int>> vv(N + 1);
	while (M--) {
		int a, b;
		cin >> a >> b;
		vv[a].push_back(b);
		v[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (v[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto a : vv[now]) {
			v[a]--;
			if (v[a] == 0)
				q.push(a);
		}
		cout << now << " ";
	}
	
}