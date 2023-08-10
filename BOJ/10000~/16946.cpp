#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
const int MAX = 1000;
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };

int arr[MAX][MAX];

struct coord {
	int y;
	int x;
};

void input(int N, int M) {
	for (int i = 0; i < N; i++) {
		char temp[MAX+1];
		cin >> temp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j]-'0';
		}
	}
}
void print(int arr[MAX][MAX], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}


void solution(int N, int M) {
	int key = 0;
	int visited[MAX][MAX] = { 0 };
	coord surrounding[MAX][MAX] = { 0 };
	//전채 맵에 대해 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//방문한 좌표면 continue
			if (visited[i][j] != 0)
				continue;
			//벽인 경우 방문처리
			if (arr[i][j] == 1) {
				visited[i][j] = 1;
			}
			else {
				queue<coord> q;
				vector<coord>v;
				q.push({ i,j });
				int cnt = 1;
				visited[i][j] = 1;
				v.push_back({ i,j });
				while (!q.empty()) {
					coord c = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int y = c.y + dy[i], x = c.x + dx[i];
						if (y < 0 || x < 0 || y >= N || x >= M)
							continue;
						if (visited[y][x] == 0 && arr[y][x] == 0) {
							q.push({ y,x });
							v.push_back({ y,x });
							visited[y][x] = 1;
							cnt++;
						}
					}
				}
				for (auto a : v) {
					surrounding[a.y][a.x] = { cnt,key };
				}
				key++;
			}
		}
	}
	//print(surrounding, N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << 0;
				continue;
			}
			unordered_map <int, int> m;
			int sum = 1;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k], x = j + dx[k];
				if (y < 0 || x < 0 || y >= N || x >= M||surrounding[y][x].y == 0)
					continue;
				if (m[surrounding[y][x].x] != 1) {
					//cout <<"+"<< surrounding[y][x].y<<", key: "<<surrounding[y][x].x;
					sum += surrounding[y][x].y;
					m[surrounding[y][x].x] = 1;
				}
					

			}
			cout << sum%10;
		}
		cout << "\n";
	}

}

int main() {
	int N,M;
	cin >> N>>M;
	input(N,M);
	solution(N,M);
}