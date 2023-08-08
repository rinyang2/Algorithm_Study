#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 301;
const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int arr[MAX][MAX];
int C, R;
int completed[MAX][MAX] = { 0 };

void input() {
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
}

void print(int arr[MAX][MAX]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

struct coord {
	int y;
	int x;
	//최소힙 구성을 위한 연산자 오버로딩
	bool operator<(coord c) const {
		return arr[y][x] > arr[c.y][c.x];
	}
};

bool canfill(int y, int x) {
	bool all_lower = true;
	bool one_lower = true;
	int original = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i], xx = x + dx[i];
		//범위 초과인 경우 물을 채울 수 없음
		if (yy<0 || xx<0 || yy>=R || xx>=C)
			return false;
		int next = arr[yy][xx];
		if (original <= next)
			all_lower = false;
		if (original > next)
			one_lower = false;
	}
	//사면이 높이가 더 낮은 경우 물을 아예 채울 수 없는 경우이므로 완료처리
	if (all_lower) {
		completed[y][x] = 1;
		return false;
	}
	return one_lower;
}

int bfs(int y, int x) {
	//bfs 시퀀스동안 방문한 노드를 모두 기록해줄 벡터
	vector <coord> vv;
	int meet_edge = 1;
	//방문처리를 해줄 임시 DAT배열
	int visited[MAX][MAX] = { 0 };
	queue<coord> q;
	//입력받은 시작 노드를 큐에 넣고 방문처리 해준다
	visited[y][x] = 1;
	q.push({ y,x });
	vv.push_back({ y,x });
	//시작 노드의 높이
	int this_value = arr[y][x];
	//같은 높이의 노드들을 탐색하며 인근 노드 중 가장 낮은 높이를 찾는다
	int closest_min = INT32_MAX;
	while (!q.empty()) {
		coord t = q.front();
		q.pop();

		//현재 노드에서 상하좌우로 탐색한다
		for (int i = 0; i < 4; i++) {
			int yy = t.y + dy[i], xx = t.x + dx[i];
			
			//테두리를 마주한 경우 흘러내리므로 탐색을 계속하되, 방문한 노드를 모두 완료처리 해줄 것이다
			if (yy < 0 || xx < 0 || yy >= R || xx >= C) {
				meet_edge = 0;
				continue;
			}
			int next = arr[yy][xx];
			//같은 높이인경우 queue에 넣고 탐색
			if (this_value == next && visited[yy][xx] == 0) {
				visited[yy][xx] = 1;
				vv.push_back({ yy,xx });
				q.push({ yy,xx });
			}
			//다른 높이인 경우 인근최소높이 갱신
			else {
				if (next < closest_min && next != this_value) {
					closest_min = next;
				}
			}
		}
	}
	int cnt = 0;
	if (closest_min <= this_value) {
		return 0;
	}
	//입력받은 노드로부터 탐색을 했는데 테두리까지 가버린 경우, 더이상 채울 수 없는 점들이므로
	//이번 BFS 시퀀스동안 방문한 노드를 모두 완료처리를 해준다
	if (meet_edge == 0) {
		for (auto a : vv) {
			completed[a.y][a.x] = 1;
		}
		return 0;
	}
	//이번에 방문한 같은 높이의 노드들을 모두 채울 수 있는 만큼 채워주고 cnt에 담아 리턴해준다
	else {
		for (auto a : vv) {
			arr[a.y][a.x] = closest_min;
			cnt+= closest_min - this_value;
		}
	}

	return cnt;
}

void fill() {
	priority_queue <coord> pq;
	//상하좌우가 모두 자기보다 같거나 높은 노드를 찾아 우선순위큐에 push한다
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (canfill(i, j)) {
				pq.push({ i,j});
			}
		}
	}

	int cnt = 0;
	
	while (!pq.empty()) {
		coord temp = pq.top(); pq.pop();
		//완료되 노드는 스킵
		if (completed[temp.y][temp.x] == 1)
			continue;
		int k = bfs(temp.y, temp.x);
		//bfs를 돌렸는데 리턴값이 0이 아닌 경우 물이 리턴값만큼 채워진 것이므로 cnt에 추가하고
		//더 채울 수 있는 경우가 있을 수 있으므로 다시 우선순위 큐에 push 해준다
		if (k){
			pq.push(temp);
			cnt += k;
			
		}

	}
	cout << cnt;
}

int main() {
	//어떻게든 시간을 줄여보기 위해 발악했던 흔적
	ios::sync_with_stdio(false); cin.tie(0);
	input();
	fill();
}