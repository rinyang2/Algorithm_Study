#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 100001;
vector <vector<int>> v[MAX];

int visited[MAX] = { 0 };

int N, start, finish;
int l_path = 0;
void dfs(int node, int cost) {
	if (node == finish) {
		cout << cost - l_path;
		return;
	}
	for (auto a : v[node]) {
		if (visited[a[0]] == 0) {
			int temp = l_path;
			visited[a[0]] = 1;
			if (l_path < a[1]) {
				l_path = a[1];
			}
			dfs(a[0], cost + a[1]);
			visited[a[0]] = 0;
			l_path = temp;
		}
	}
}


int main() {
	cin >> N >> start >> finish;
	for (int i = 0; i < N - 1; i++) {
		int from, to, distance;
		cin >> from >> to >> distance;
		v[from].push_back({ to, distance });
		v[to].push_back({ from, distance });
	}
	visited[start] = 1;
	dfs(start, 0);

}