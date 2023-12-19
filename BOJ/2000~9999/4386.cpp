#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;
int root[101];

struct star {
	double y;
	double x;
	int idx;
};

struct node {
	int from;
	int to;
	double dist;
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
vector<star> v;
int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		double a, b;
		cin >> a >> b;
		v.push_back({ a,b,i });
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double dist = (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
			//cout << v[i].idx << " " << v[j].idx << " " << sqrt(dist) << endl;
			vn.push_back({ v[i].idx, v[j].idx, sqrt(dist) });
		}
	}
	sort(vn.begin(), vn.end());
	for (int i = 0; i <= N; i++) {
		root[i] = i;
	}
	double cnt = 0;
	for (auto a : vn) {
		if (find(a.from) != find(a.to)) {
			Union(a.from, a.to);
			cnt += a.dist;
		}
	}
	printf("%0.2f", cnt);
}