#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000;
int N, M;

struct node {
	int to;
	int cost;
	bool operator<(node n) const {
		return cost > n.cost;
	}
};
int dist[MAX + 1];
vector<node> v[MAX + 1];
int Route[MAX + 1];
vector<int> route_v;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INT32_MAX;
	}
}

void dijkstra(int from, int to) {
	priority_queue <node> pq;

	dist[from] = 0;

	pq.push({ from,0 });
	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		int nowNode = now.to;
		int nowCost = now.cost;

		if (dist[nowNode] < nowCost)
			continue;

		for (int i = 0; i < v[nowNode].size(); i++) {
			int next = v[nowNode][i].to;
			int nextCost = v[nowNode][i].cost;
			if (dist[next] <= dist[nowNode] + nextCost)
				continue;
			Route[next] = nowNode;
			dist[next] = nowCost + nextCost;
			pq.push({ next, dist[next] });
		}
	}
	cout << dist[to] << '\n';
	int temp = to;
	while (temp) {
		route_v.push_back(temp);
		temp = Route[temp];
	}
	cout << route_v.size() << '\n';

	for (int i = route_v.size() - 1; i >= 0; i--) {
		cout << route_v[i] << " ";
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	input();
	int A, B;
	cin >> A >> B;
	dijkstra(A,B);
}