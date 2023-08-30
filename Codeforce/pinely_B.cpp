#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cmath>
#include<unordered_map>
#define endl '\n'
using namespace std;



void solve() {
	int n, cnt = 0;
	cin >> n;
	unordered_map<int, int> um;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		um[v[i]] = i;
	}

	for (auto a : v) {
		if (a != 1) {
			int x = um[a], y = um[a - 1];
			if (x < y)
				cnt++;
		}
	}
	cout << cnt << endl;
}



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
        solve();
	}
}