#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;
int root[100001];

struct node {
	int from;
	int to;
	int dist;
	bool operator<(node n) {
		return dist < n.dist;
	}
};

int find(int a) {
	if (a == root[a])
		return a;
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

vector<node> vn;

int N,M;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N>>M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b>> c;
		vn.push_back({ a,b,c });
	}
	
	sort(vn.begin(), vn.end());
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}
	int cnt = 0;
	int maxval = 0;
	for (auto a : vn) {
		if (find(a.from) != find(a.to)) {
			Union(a.from, a.to);
			cnt += a.dist;
			maxval = max(maxval, a.dist);
		}
	}
	cout << cnt-maxval;
}