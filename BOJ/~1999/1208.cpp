#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
int N, S;
int arr[41];
//중간에서 만나기 활용
vector<int> l, r;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N/2; i++) {
		int temp; cin >> temp;
		l.push_back(temp);
	}
	for (int i = N / 2; i < N; i++) {
		int temp; cin >> temp;
		r.push_back(temp);
	}
}

vector <int> qwe;
unordered_map<int,int> subarr(vector <int> v) {
	int n = v.size();
	unordered_map <int, int> temp;
    //비트 연산자를 이용한 모든 부분집합의 합 구하기
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += v[j];
			}
		}
		temp[sum] += 1;
		qwe.push_back(sum);
	}
    //공집합 처리
	temp[0] -= 1;
	return temp;
}

void solution() {
	long long cnt = 0;
	
	unordered_map<int, int>	w = subarr(r);

	qwe.clear();
	unordered_map<int, int> q = subarr(l);
    //공집합 처리를 위해 i=1부터
	for (int i = 1; i < qwe.size(); i++) {
		cnt += w[S - qwe[i]];
	}
	cout << cnt + q[S] + w[S];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solution();
}