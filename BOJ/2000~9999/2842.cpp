#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<vector>
#include<queue>
#define endl '\n'
#define MAX 50
using namespace std;
//상하좌우대각선
const int dy[] = { 0,0,1,-1,1,1,-1,-1 }, dx[] = { 1,-1,0,0,1,-1,1,-1 };
struct coord {
	int y;
	int x;
};

int N;
char arr[MAX][MAX+1];
int alt[MAX][MAX];
int start_alt;
// 고도들의 종류를 담을 벡터 v
vector <int> v;

// 우체국의 위치 P의 좌표
coord st;

// 'K'들의 좌표를 담을 벡터
vector<coord> Ks;

void debug() {
	cout << endl << "Altitudes: " << endl;
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
	cout << endl<< "Starting Position(P) : ";
	cout <<"("<< st.y << "," << st.x<<")" << endl;
	cout << endl;
	cout << "positions of Houses(K) : "<<endl;
	for (auto a : Ks) {
		cout << "(" << a.y << "," << a.x << ")" << endl;
	}
	cout << "start_alt: " << start_alt<<endl;
}

void printarr(int arr[][50]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs(int l, int r) {
	//cout << v[l] << " <= x <= " << v[r] << " 인 고도만 탐색" << endl;

	int vl = v[l], vr = v[r];
	//방문하는동안 최대고도, 최소고도를 갱신해줘야 한다
	//vr-vl을 리턴하면 vr,vl값 칸을 방문하지 못하는 testcase에서 틀린 답이 나오게 됨
	int mini = start_alt, maxi = start_alt;
	queue<coord> q;
	int visited[50][50] = { 0 };
	visited[st.y][st.x] = 1;
	q.push({ st.y, st.x });
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int y = now.y + dy[i], x = now.x + dx[i];

			//범위 초과시 탐색 하지 않음
			if (y < 0 || x < 0 || y >= N || x >= N)
				continue;
			int next_val = alt[y][x];
			//탐색한 칸이 v[l]<=next<=v[r] 범위 내 값이 아니면 탐색하지 않음
			if (next_val > vr || next_val < vl)
				continue;
			//방문하지 않은 경우에만 탐색
			if (visited[y][x] == 0) {
				visited[y][x] = 1;
				int temp = alt[y][x];
				if (temp > maxi)
					maxi = temp;
				if (temp < mini)
					mini = temp;
				q.push({ y,x });
			}

		}
	}

	//printarr(visited);

	for (auto a : Ks) {
		//방문하지 않은 집이 있는 경우 -1 리턴
		if (visited[a.y][a.x] == 0)
			return -1;
	}
	return maxi-mini;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'P') {
				st.y = i;
				st.x = j;
			}
			else if (arr[i][j] == 'K')
				Ks.push_back({ i,j });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			alt[i][j] = temp;
			v.push_back(temp);
		}
	}
	start_alt = alt[st.y][st.x];
	// 고도들을 정렬, 단일화 한 후 이를 바탕으로 투포인터를 진행할 것이다
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int lp = 0, rp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == start_alt) {
			rp = i;
			break;
		}
	}

	
	//debug();
	//cout << lp << " " << rp << endl;
	
	int vsize = v.size();
	int answer = INT32_MAX;
	while (lp < vsize && rp < vsize) {
		int temp = bfs(lp, rp);
		//집을 모두 탐색하지 못한 경우 rp++
		if (temp == -1)
			rp++;
		//집을 모두 탐색한 경우 최소값 갱신 후 lp++
		else {
			lp++;
			answer = min(answer, temp);
		}
	}
	cout << answer;
}