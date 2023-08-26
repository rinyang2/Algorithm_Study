#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl '\n'

bool solution() {
	int n;
	cin >> n;

	int t;
	if (n % 2 == 0) {
		t = n / 2;
	}
	else {
		t = n / 2 + 1;
	}

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1) {
		if (v[0] == 1)
			return true;
		return false;
	}

	vector<int> nv;
	for (int i = 0; i <n-1; i++) {
		for (int j = 0; j < v[i] - v[i+1]; j++) {
			nv.push_back(i+1);
		}
		if (nv.size() > n)
			return false;
	}

	
	if (v[0] != n)
		return false;
	
	int ss = nv.size();
	for (int i = 0; i <n; i++) {
		if (i >= ss) {
			if (v[n - i - 1] != n)
				return false;
			continue;
		}
		if (nv[i] != v[n - i - 1])
			return false;
	}
	return true;

}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		if (solution()) {
			cout << "YES"<<endl;
		}
		else {
			cout << "NO"<<endl;
		}
	}
}