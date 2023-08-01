#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 21;
vector <int> v[MAX*MAX];
int visited[MAX*MAX] = { 0 };
int R, C;
char arr[MAX][MAX];
int alphabet[26] = { 0 };
void print() {
	for (int i = 0; i <= C*R; i++) {
		cout << i << " : ";
		for (auto a : v[i]) {
			cout << a << " ";
		}
		cout << endl;
	}
}

void preprocess() {
	int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k], x = j + dx[k];
				if (y >= 0 && x >= 0 && y < R && x < C) {
					if (arr[i][j] != arr[y][x]) {
						v[i * C + j].push_back(y * C + x);
					}
				}
			}


		}
	}
}

int max_level = 0;
void bfs(int node, int level) {
	if (level > max_level) {
		max_level = level;
	}
	for (auto a : v[node]) {
		if (visited[a] == 0 && alphabet[arr[a/C][a%C] - 'A'] == 0) {
			visited[a] = 1;
			alphabet[arr[a / C][a % C] - 'A'] = 1;
			bfs(a, level + 1);
			visited[a] = 0;
			alphabet[arr[a / C][a % C] - 'A'] = 0;
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	preprocess();
	alphabet[arr[0][0] - 'A'] = 1;
	visited[0] = 1;
	bfs(0, 0);
	cout << max_level+1;

}