#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1234567890;

//최단거리 정보를 담을 dist[node 번호][들린 node의 개수]
int dist[1001][1001];

int N, M, K;
struct edge {
	int index;
	int cost;
	int node_cnt; //node를 들린 횟수
	//priority queue에서 가중치가 작은 값이 top에 위치함
	bool operator<(edge e) const {
		return cost > e.cost;
	}
};

//도시에 연결된 도로정보를 담을 vector
vector<edge> v[1001];

void dijkstra(int st) {
	priority_queue <edge> pq;
	//시작 도시는 0번만에 가능
	dist[st][0] = 0;
	pq.push({ st, 0 ,0 });

	//dijkstra (wc: 30000*log2(30000) * 30 = 13500000)
	while (!pq.empty()) {
		edge nowEdge = pq.top(); pq.pop();
		int now_index = nowEdge.index;
		int now_cost = nowEdge.cost;
		int now_node_cnt = nowEdge.node_cnt;


		if (now_cost > dist[now_index][now_node_cnt]) continue;

		//현재 노드와 연결된 모든 간선에 대해
		for (auto a : v[now_index]) {
			int next_index = a.index;
			int next_cost = a.cost;

			if (dist[next_index][now_node_cnt + 1] > now_cost + next_cost) {
				dist[next_index][now_node_cnt + 1] = now_cost + next_cost;
				pq.push({ next_index, now_cost + next_cost, now_node_cnt + 1 });
			}

		}

	}
}

int main() {
	//입출력 시간 줄이기
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//첫 번째 줄에 도시의 수 N (2 ≤ N ≤ 1,000), 고속도로의 수 M (1 ≤ M ≤ 30,000), 그리고 햇수 K (0 ≤ K ≤ 30,000)가 주어집니다.
	cin >> N >> M >> K;
	//두 번째 줄에는 도시 A와 도시 B (1 ≤ A, B ≤ N, A ≠ B)가 주어집니다.
	int A, B;
	cin >> A >> B;
	//다음 M개의 줄에는 각각 도로 정보를 나타내는 세 정수 f, t (1 ≤ f < t ≤ N), c (1 ≤ c ≤ 1,000)가 주어집니다.
	//모두 INF로 초기화 (wc: 1000000)
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
		}
	}
	while (M--) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	dijkstra(A);
	int ans = INF;
	for (int i = 0; i < N; i++) {
		if (dist[B][i] < ans)
			ans = dist[B][i];
	}
	cout << ans << "\n";
	int sum = 0;

	//wc: K*N = 30000000
	while (K--) {
		int a;
		cin >> a;
		sum += a;
		ans = INF;
		for (int i = 1; i < N; i++) {
			int k = dist[B][i] + sum * i;
			ans = min(ans, k);
		}
		cout << ans << "\n";
	}

}