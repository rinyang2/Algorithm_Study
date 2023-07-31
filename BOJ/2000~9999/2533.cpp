#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector <int> v[MAX];
vector <int> path;

int  cnt = 0;
int visited[MAX] = { 0 };

bool dfs(int node) {
	visited[node] = 1;
	//leaf node 인 경우
	if (v[node].empty()) {
		//얼리어답터가 무조건 아니므로 false리턴
		return false;
	}
	//자식 노드중 하나라도 얼리어답터가 아니라면
	bool b = false;
	for (auto a : v[node]) {
		if (visited[a] == 0) {
			if (dfs(a) == false) {
				b = true;
			}
		}
	}
	//부모는 얼리어답터이다
	if (b) {
		cnt++;
	}
	return b;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);

	cout << cnt;
}