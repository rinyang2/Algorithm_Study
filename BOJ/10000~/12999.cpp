#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl '\n'
#define MAX 100101
using namespace std;
int N, Q;
int sn = 316;
//13547번과 99% 같지만 입력 범위가 -10만부터라 cnt배열 크기를 2배로 해주고
//10만을 더한값을 쓰도록 함
struct qry {
	int l, r, index;
	//제곱근 분할법에 따른 쿼리 정렬을 위한 연산자 오버로딩
	bool operator<(qry q) const {
		if (l / sn == q.l / sn)
			return r < q.r;
		return l / sn < q.l / sn;
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//첫째 줄에 수열의 크기 N이 주어진다
	cin >> N >> Q;
	//둘째 줄에는 수열이 주어진다
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//셋째 줄에는 쿼리의 개수 M이 주어진다
	
	//넷째 줄부터 M개의 줄에는 쿼리가 주어진다
	vector<qry> qrs;
	for (int i = 0; i <Q; i++) {
		int a, b;
		cin >> a >> b;
		qry q;
		q.l = a - 1;
		q.r = b - 1;
		q.index = i;
		qrs.push_back(q);
	}


	//mo's algorithm에 맞게 정렬
	sort(qrs.begin(), qrs.end());

	//숫자 개수으 최대값을 기록할 변수
	int res = 0;

	//쿼리 범위 내의 숫자 개수를 기록할 DAT
	int cnt[MAX*2] = { 0 };

	//해당 숫자의 개수의 개수를 기록할 DAT
	int table[MAX] = { 0 };
	table[0] = N;
	//쿼리 순서에 따른 result
	vector<int> result(Q);



	//left pointer, right pointer
	int lp = qrs[0].l, rp = lp - 1;

	for (int i = 0; i < qrs.size(); i++) {
		int l = qrs[i].l;
		int r = qrs[i].r;
		/*cout << endl<<l+1 << " " << r+1 << endl;*/
		while (lp > l) {
			lp--;
			int now = arr[lp]+100000;
			cnt[now]++;
			table[cnt[now]]++;
			table[cnt[now] - 1]--;
			res = max(res, cnt[now]);
		}

		while (rp < r) {
			rp++;
			int now = arr[rp] + 100000;
			cnt[now]++;
			table[cnt[now]]++;
			table[cnt[now] - 1]--;
			res = max(res, cnt[now]);
		}

		while (lp < l) {
			int now = arr[lp] + 100000;
			if (cnt[now])
				table[cnt[now]]--;
			if (table[cnt[now]] == 0 && cnt[now] == res)
				res -= 1;
			table[cnt[now] - 1]++;
			cnt[now]--;
			lp++;
		}

		while (rp > r) {
			int now = arr[rp] + 100000;
			if (cnt[now])
				table[cnt[now]]--;
			if (table[cnt[now]] == 0 && cnt[now] == res)
				res -= 1;
			table[cnt[now] - 1]++;
			cnt[now]--;
			rp--;
		}

		result[qrs[i].index] = res;
	}

	for (int i = 0; i < Q; i++) {
		cout << result[i] << endl;
	}
}