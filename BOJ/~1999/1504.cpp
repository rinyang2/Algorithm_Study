#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 200001
#define INF INT32_MAX
using namespace std;

struct edge {
	int to;
	int cost;
	bool operator<(edge e) const{
		return cost > e.cost;
	}
};
//정점의 개수 N과 간선의 개수 E
int N, E;
vector <edge> v[MAX];
//반드시 거쳐야 하는 두개의 서로 다른 정점 번호  A,B
int A, B;

void input() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> A >> B;
}

void dijkstra(int A, int B) {
	priority_queue<edge> pq;
	int dist_A[MAX], dist_B[MAX];
	for (int i = 1; i <= N; i++) {
		dist_A[i] = INF;
		dist_B[i] = INF;
	}
	//정점 A부터 다익스트라
	dist_A[A] = 0;
	pq.push({ A , 0 });
	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		int now = e.to;
		int nowCost = e.cost;
		if (dist_A[now] < nowCost)
			continue;
		for (auto a : v[now]) {
			int next = a.to;
			int nextCost = a.cost;

			if (dist_A[next] <= nowCost + nextCost)
				continue;
			dist_A[next] = nowCost + nextCost;
			pq.push({ next,dist_A[next] });
		}
	}
	dist_B[B] = 0;
	pq.push({ B , 0 });
	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		int now = e.to;
		int nowCost = e.cost;
		if (dist_B[now] < nowCost)
			continue;
		for (auto a : v[now]) {
			int next = a.to;
			int nextCost = a.cost;

			if (dist_B[next] <= nowCost + nextCost)
				continue;
			dist_B[next] = nowCost + nextCost;
			pq.push({ next,dist_B[next] });
		}
	}
	if (dist_A[1] == INF || dist_A[N] == INF || dist_A[B] == INF || dist_B[1] == INF || dist_B[N] == INF) {
		cout << -1;
		return;
	}
		
	cout<< min(dist_A[1] + dist_B[N] + dist_A[B], dist_B[1] + dist_A[N] + dist_A[B]);

}



int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	input();
	dijkstra(A, B);
}