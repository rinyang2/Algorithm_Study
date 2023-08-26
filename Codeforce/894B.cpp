#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl '\n'

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> nv;
	nv.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (v[i - 1] > v[i]) {
			nv.push_back(v[i]);
		}
		nv.push_back(v[i]);
	}
	cout << nv.size() << endl;
	for (auto a : nv) {
		cout << a << " ";
	}
	cout << endl;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solution();
	}
}