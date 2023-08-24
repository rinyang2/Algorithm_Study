#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

#define endl '\n'
int sq;
using namespace std;

struct query {
	int first;
	int second;
	int index;
	bool operator<(query q) const {
		if (first / sq == q.first / sq)
			return second < q.second;
		return first / sq < q.first / sq;
	}
};

vector<int> v;
//어떤 숫자가 어떤 인덱스에 있는지 순서대로 담을 자료구조 deque
deque<int> dq[100001];
//max(back-front)를 구하기 위한 table
int table[100001] = { 0 };

void Plus(int n) {

}

void Minus(int n) {

}


int main() {
	//입력파트
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;

	v.resize(N);
	sq = int(sqrt(N));

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cin >> M;
	vector<query> q;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back({ a-1,b-1,i });
	}

	//알고리즘 적용 파트
	
	//제곱근 분할법 mo's 쿼리 정렬
	sort(q.begin(), q.end());

	//투포인터
	int lp = q[0].first; 
	int rp = q[0].second;

	//첫 쿼리는 bruteforce하게
	for (int i = lp; i <= rp; i++) {
		//v[i]라는 숫자는 i인덱스 위치에 있다
		dq[v[i]].push_back(i);
		if (dq[v[i]].size() >= 2)
			table[dq[v[i]].back() - dq[v[i]].front()]++;
	}


	//쿼리 수행
	for (auto a : q) {
		int l = a.first, r = a.second;

		//push
		while (lp > l) {
			Plus(--lp);
		}
		//push
		while (rp < r) {
			Plus(++rp);
		}
		//pop
		while (rp > r) {
			Minus(rp--);
		}
		//pop
		while (lp < l) {
			Minus(lp++);
		}
	}
}