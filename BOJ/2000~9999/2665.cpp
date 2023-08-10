#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 50;
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };

int arr[MAX][MAX];

struct coord {
	int y;
	int x;
	int priority;
	bool operator < (coord n) const {
		return priority > n.priority;
	}
};

void input(int N) {
	for (int i = 0; i < N; i++) {
		char temp[MAX+1];
		cin >> temp;
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[j]-'0';
		}
	}
}
void print(int arr[MAX][MAX], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void solution(int N) {
	int visited[MAX][MAX] = { 0 };
	priority_queue<coord> q;
	visited[0][0] = 1;
	q.push({ 0,0, 0});
	while (!q.empty()) {
		coord c = q.top(); q.pop();
		if (c.y == N - 1 && c.x == N - 1) {
			cout << c.priority;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int y = c.y + dy[i], x = c.x + dx[i];
			if (y < 0 || x < 0 || y >= N || x >= N || visited[y][x] != 0)
				continue;
			visited[c.y][c.x] = 1;
			if ( arr[c.y][c.x] == 1) {
				q.push({ y,x,c.priority });
			}
			else if(arr[c.y][c.x] == 0){
				q.push({ y,x,c.priority +1});
			}
				
		}
	}

}

int main() {
	int N;
	cin >> N;
	input(N);
	//print(N);
	solution(N);
}