#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 100001;
vector <int> v_better[MAX];
vector <int> v_worse[MAX];

int visited[MAX] = { 0 };
int visited_re[MAX] = { 0 };
int N, M;

int cnt_b = 0, cnt_w = 0;

void dfs(int node) {
	for (auto a : v_better[node]) {
		if (visited[a] == 0) {
			visited[a] = 1;
			cnt_b++;
			dfs(a);
		}
	}
}

void dfs_re(int node) {
	for (auto a : v_worse[node]) {
		if (visited_re[a] == 0) {
			visited_re[a] = 1;
			cnt_w++;
			dfs_re(a);
		}
	}
}

int main() {
	int X;

	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++) {
		int from, to;
		cin >> from >> to;
		//내가 얘보다 잘함
		v_better[from].push_back(to);
		//내가 얘보다는 못함
		v_worse[to].push_back(from);
	}
	dfs(X);
	dfs_re(X);

	cout << 1 + cnt_w << " " << N - cnt_b;

}