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
vector<query> queries;
vector<int> arr;
vector<int> answer;
unordered_map<int, int> umap;
vector<int> zip;
int cntt[1010101] = { 0 };


int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	int N, Q;
	cin >> N;

	arr.resize(N);
	
	sqrtN= int(sqrt(N));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		zip.push_back(arr[i]);
		//unordered_map을 이용한 좌표압축
		/*if (umap.find(arr[i]) == umap.end()) {
			umap.insert(make_pair(arr[i], i));
		}*/
	}
	sort(zip.begin(), zip.end());
	zip.erase(unique(zip.begin(), zip.end()), zip.end());
	cin >> Q;
	answer.resize(Q);
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		queries.push_back({ a - 1,b - 1,i });
	}

	//알고리즘 적용 파트



	//제곱근 분할법 mo's 쿼리 정렬
	sort(queries.begin(), queries.end());

	//투포인터
	int lp = queries[0].first;
	int rp = queries[0].second;
	int cnt = 0;
	
	for (int i = lp; i <= rp; i++) {
		int index= lower_bound(zip.begin(), zip.end(), arr[i]) - zip.begin();
		cntt[index]++;
		if (cntt[index] == 1) {
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
			int A = lower_bound(zip.begin(), zip.end(), arr[lp]) - zip.begin();
			cntt[A]++;
			if (cntt[A] == 1) {
				cnt++;
			}
		}
		//push
		while (rp < r) {
			rp++;
			int A = lower_bound(zip.begin(), zip.end(), arr[rp]) - zip.begin();
			cntt[A]++;
			if (cntt[A] == 1) {
				cnt++;
			}
		}
		//pop
		while (rp > r) {
			int A = lower_bound(zip.begin(), zip.end(), arr[rp]) - zip.begin();
			if (cntt[A] == 1) {
				cnt--;
			}
			cntt[A]--;
			rp--;
		}
		//pop
		while (lp < l) {
			int A = lower_bound(zip.begin(), zip.end(), arr[lp]) - zip.begin();
			if (cntt[A] == 1) {
				cnt--;
			}
			cntt[A]--;
			lp++;
		}

		answer[queries[i].index] = cnt;
	}

	for (auto a : answer) {
		cout << a <<endl;
	}
}