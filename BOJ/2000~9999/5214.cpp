#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200000;
vector <int> hypertube[MAX];
vector <int> nodes[MAX];
int visited[MAX] = { 0 };

int N, K, M;

void input() {
	cin >> N >> K >> M;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < K; j++) {
				int a;
				cin >> a;
				//i번 key의 하이퍼튜브에는 K개의 노드정보가 담겨있다
				hypertube[i].push_back(a);
				//각 노드에는 연결된 하이퍼튜브의 키들이 담겨있다
				nodes[a].push_back(i);
			}
		}
		//예외처리
		if (N == 1) {
			cout << 1;
			exit(0);
		}
}


//dfs를 통한 완전탐색
void dfs(int n) {
	queue <int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto a : nodes[x]) {
			for (auto b : hypertube[a]) {
				//탐색 중 찾은 경우 탐색을 멈추고 프로그램 종료
				if (b == N) {
					cout << visited[x] + 1;
					exit(0);
				}
				if (visited[b] == 0) {
					q.push(b);
					visited[b] = visited[x] + 1;
				}
			}
		}
	}
}

int main() {
	input();
	dfs(1);
	//마지막에 탐색되는 경우가 있으므로 if-else를 써줘야 했다
	if (visited[N])
		cout << visited[N];
	else
		cout << -1;

}