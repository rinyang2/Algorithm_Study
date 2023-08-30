#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;



int main() {
	int N, S;
	cin >> N >> S;
	vector<int> v(N+1);
	v[0] = 0;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		v[i] = temp + v[i - 1];
	}


	if (v.back() < S) {
		cout << "0";
		return 0;
	}
	int ans = INT32_MAX;
	for (int i = 0; i < N; i++) {
		int temp = lower_bound(v.begin(), v.end(), v[i] + S) - v.begin();
		if (temp == N+1)
			continue;
		ans =min(ans,temp-i);
	}
	cout << ans;
}