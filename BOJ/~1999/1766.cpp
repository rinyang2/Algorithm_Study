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
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> asd;
	for (int i = 1; i <= N; i++) {
		if (v[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int now = pq.top(); pq.pop();
		for (auto a : vv[now]) {
			v[a]--;
			if (v[a] == 0)
				asd.push_back(a);
		}

			for (auto a : asd) {
				pq.push(a);
			}
			asd.clear();
		
		
		cout << now << " ";
	}
	
}