#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cmath>
#include<bitset>
#define endl '\n'
using namespace std;



void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 1; i < n; i *= 2) {
		ans.push_back(i);
	}
	int temp = n - ans.back();
	vector <int> v;
	while (temp != 0) {
		if (temp % 2 == 0) {
			v.push_back(0);
		}
		else {
			v.push_back(1);
		}
		temp/=2;
	}
	int k = 1;
	vector<int> v2;
	for (auto a : v) {
		if (a == 1)
			v2.push_back(k);
		k *= 2;
	}
	for (int i = v2.size() - 1; i >= 0; i--) {
		int t = ans.back();
		ans.push_back(t + v2[i]);
	}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	cout << endl;
}



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
        solve();
	}
}