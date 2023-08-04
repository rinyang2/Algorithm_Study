#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = INT32_MAX;
int N;
struct edge {
	int to;
	int time;
	bool operator<(edge e) const {
		return time > e.time;
	}
};


//시작점 st, 시작점에서 각 점까지 최소거리를 담을 배열 dist, 간선 정보가 담긴 벡터 v
void dijkstra(int st, int dist[], vector<edge> v[]) {
	//최소거리를 전부 무한대로 초기화 해준다
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	//시작점의 거리는 0으로 하고 heap에 넣어준다
	dist[st] = 0;
	priority_queue<edge> pq;
	pq.push({ st, 0 });

	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		int now = e.to, nowTime = e.time;
		if (dist[now] < nowTime)
			continue;
		//top노드에 연결된 모든 간선에 대해 반복
		for (int i = 0; i < v[now].size(); i++) {
			edge nextE = v[now][i];
			int next = nextE.to;
			int nextTime = nextE.time;
			if (dist[next] <= dist[now] + nextTime) {
				continue;
			}
			dist[next] = dist[now] + nextTime;
			pq.push({ next, dist[next] });
		}

	}
}

int main() {
	vector<edge> v[1001];

	int dist[1001];

	int M;

	cin >> N >> M;
	while (M--) {
		int from, to, time;
		cin >> from >> to >> time;
		v[from].push_back({ to, time });
	}

	int f, t;
	cin >> f >> t;
	dijkstra(f, dist, v);
	cout<< dist[t];

}