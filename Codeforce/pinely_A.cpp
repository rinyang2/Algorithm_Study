#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cmath>
#include<bitset>
#define endl '\n'
using namespace std;



void solve() {
	int n, a, q;
	cin >> n >> a >> q;
	int c = a;
	int minu=0, plu=0;
	string s;
	cin >> s;
	if (n == a) {
		cout << "YES" << endl;
		return;
	}
	for (auto a : s) {
		if (a == '+') {
			c++;
			plu++;
		}
		else {
			c--;
			minu--;
		}
		if (c == n) {
			cout << "YES" << endl;
			return;
		}
	}

	if (plu + a >= n) {
		cout << "MAYBE" << endl;
	}
	else {
		cout << "NO" << endl;
	}


}



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
        solve();
	}
}