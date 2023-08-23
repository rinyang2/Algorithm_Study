/*
Little Mirko is a very simple man. 
Mirko’s friend Darko has given him an array of N natural integers and asked him Q queries about the array that Mirko must answer.
Each query consists of two integers, the positions of the left and right end of an interval in the array. 
The answer to the query is the number of different values that appear exactly twice in the given interval.

The first line of input contains the integers N and Q (1 ≤ N, Q ≤ 500 000).
The second line of input contains N natural integers less than 1 000 000 000, the elements of the array.
Each of the following Q lines contains two integers, L and R (1 ≤ L ≤ R ≤ N), from the task.

The output must consist of Q lines, each line containing the answer to a query, respectively.
*/
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

#define endl '\n'
int sqrtN;
using namespace std;

struct query {
	int first;
	int second;
	int index;
	bool operator<(query q) const {
		if (first / sqrtN == q.first / sqrtN)
			return second < q.second;
		return first / sqrtN < q.first / sqrtN;
	}
};

vector<int> arr;

unordered_map<int, int> umap;

int cntt[505050] = { 0 };


int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	int N, Q;
	cin >> N >> Q;

	arr.resize(N);
	sqrtN= int(sqrt(N));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		//unordered map으로 좌표압축에만 사용한다
		//make_pair를 써야 시간초과가 안남
		if (umap.find(arr[i]) == umap.end()) {
			umap.insert(make_pair(arr[i], i));
		}
	}

	vector<query> queries;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		queries.push_back({ a - 1,b - 1,i });
	}

	//알고리즘 적용 파트

	vector<int> answer(Q);

	//제곱근 분할법 mo's 쿼리 정렬
	sort(queries.begin(), queries.end());

	//투포인터
	int lp = queries[0].first;
	int rp = queries[0].second;
	int cnt = 0;

	for (int i = lp; i <= rp; i++) {
		if (cntt[arr[i]] == 2) {
			cnt--;
		}
		cntt[arr[i]]++;
		if (cntt[arr[i]] == 2) {
			cnt++;
		}
	}
	answer[queries[0].index] = cnt;
	//쿼리 수행
	for (int i = 1; i < queries.size(); i++) {
		int l = queries[i].first, r = queries[i].second;

		//push
		while (lp > l) {
			lp--;
			int A = arr[lp];
			if (cntt[A] == 2) {
				cnt--;
			}
			cntt[A]++;
			if (cntt[A] == 2) {
				cnt++;
			}
		}
		//push
		while (rp < r) {
			rp++;
			int A = arr[rp];
			if (cntt[A] == 2) {
				cnt--;
			}
			cntt[A]++;
			if (cntt[A] == 2) {
				cnt++;
			}
		}
		//pop
		while (rp > r) {
			int A = arr[rp];
			if (cntt[A] == 2) {
				cnt--;
			}
			cntt[A]--;
			if (cntt[A] == 2) {
				cnt++;
			}
			rp--;
		}
		//pop
		while (lp < l) {
			int A = arr[lp];
			if (cntt[A] == 2) {
				cnt--;
			}
			cntt[A]--;
			if (cntt[A] == 2) {
				cnt++;
			}
			lp++;
		}

		answer[queries[i].index] = cnt;
	}

	for (auto a : answer) {
		cout << a <<endl;
	}
}