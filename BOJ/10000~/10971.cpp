#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 13;
vector <vector<int>> v[MAX];
vector<int> path;
int visited[MAX] = { 0 };
int N;


//최소거리를 담을 변수
int min_distance = 213456890;

void reset() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
}

void dfs(int node, int cost, int start) {

	if (path.size() == N-1) {
		for (auto a : v[path.back()]) {
			if (a[0] == start) {
				if (a[1] + cost < min_distance) {
					min_distance = a[1] + cost;
				}
			}
		}
		return;
	}	
	
	for (auto a : v[node]) {
		int foo = a[0];
		if (visited[foo] == 0) {
			if (cost + a[1] >= min_distance) continue;
			visited[foo] = 1;

			path.push_back(foo);

			dfs(foo, cost + a[1], start);

			visited[foo] = 0;

			path.pop_back();
		}
	}


}

int main() {
	//트리 정점의 개수가 주어진다
	cin >> N;
	//트리를 입력받는다
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int vertex;
			cin >> vertex;
			if (vertex != 0) {
				v[i].push_back({j,vertex});
			}
			
		}
	}
	
	for (int i = 1; i <= N; i++) {
		reset();
		visited[i] = 1;
		dfs(i, 0, i);
	}
	cout << min_distance;
}