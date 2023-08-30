#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int x, y, n;
	cin >> x >> y >> n;
	if (y - x < n * (n - 1) / 2) {
		cout << -1 << endl;
		return;
	}
	vector<int> v;
	v.resize(n);
	v[0] = y;
	for (int i = 1; i <= n - 2; i++) {
		v[i] = v[i - 1] - i;
	}
	v[n - 1] = x;
	for (int i = v.size()-1; i >= 0; i--) {
		cout << v[i] << " ";
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