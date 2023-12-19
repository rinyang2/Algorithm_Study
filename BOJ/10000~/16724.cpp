#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>

#define endl '\n'
using namespace std;

vector<int> root;

int find(int a) {
	if (a == root[a]) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (b < a)
		root[a] = b;
	else
		root[b] = a;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N,M;
	cin >> N>>M;
	root.resize(N*M + 1);
	for (int i = 0; i <= N * M; i++) {
		root[i] = i;
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			int cur = i * M + j;
			if (s[j] == 'D') {
				Union(cur, M*i + j + M);
			}
			else if (s[j] == 'L') {
				Union(cur, M*i + j -1);
			}
			else if (s[j] == 'R') {
				Union(cur, M*i + j + 1);
			}
			else if (s[j] == 'U') {
				Union(cur, M*i + j - M);
			}
		}
	}
	unordered_map <int, int> um;
	int cnt = 0;
	for (int i = 0; i < N*M; i++) {
		int t = find(i);
		if (um[t] == 0)
			cnt++;
		um[t]++;
	}
	cout << cnt;
}