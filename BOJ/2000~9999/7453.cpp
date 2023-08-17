#include <iostream>
#include <algorithm>
//#include <unordered_map>
#include <vector>

using namespace std;
int arr[4000][4];
int N;
//해시맵은 입력 데이터가 커지는 경우 해시충돌로 인해 느려지므로 이분탐색이 더 빠르다고 합니다
// 그리고 해시맵 쓰니까 메모리 초과 났음
//unordered_map <int, int> um;

vector <int>v;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
}
void solution() {
	long long cnt = 0;
	//unordered_map<int,int>um;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(arr[i][0] + arr[j][1]);
			//um[arr[i][1] + arr[j][2]]++;
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = -arr[i][2] - arr[j][3];
			//자동으로 이분탐색을 해주는 멋진 팡션 equal_range
			auto a = equal_range(v.begin(), v.end(), temp);
			cnt += a.second - a.first;
		}
	}

	cout<< cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solution();
}