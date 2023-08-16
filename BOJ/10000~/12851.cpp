#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int N, K;
bool visited[100001];

struct node {
	int now;
	int time;
};

void bfs() {
	if (N == K) {
		cout << 0 << '\n' << 1 << endl;
		return;
	}
	queue<node> q;
	visited[N] = true;
	q.push({ N,0 });
	int mintime;
	int cnt = 0;
	while (!q.empty()) {
		node t = q.front(); 
		int now = t.now;
		q.pop();
		visited[t.now] = 1;
		if (cnt && now == K && mintime == t.time)
			cnt++;
		if (!cnt && now == K) {
			mintime = t.time;
			cnt++;
		}
		int temp[3] = { now - 1, now + 1, now * 2 };
		for (int i = 0; i < 3; i++) {
			if (temp[i] >= 0 && temp[i] <= 100000 && visited[temp[i]] == 0) {
				q.push({ temp[i], t.time + 1 });
			}
		}
	}
	cout << mintime << endl;
	cout << cnt << endl;
}

int main() {
	cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
	cin >> N >> K;
	bfs();
}