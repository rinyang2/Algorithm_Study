#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cmath>
#include<bitset>
#define endl '\n'
using namespace std;



void solve() {
	int n, k;
	cin >> n >> k;
	vector<int>v;
	vector<bool> asd(n + 1);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		asd[temp] = true;
	}
	int missing;
	for (int i = 0; i < n + 1; i++) {
		if (asd[i] == false) {
			missing = i;
			break;
		}
	}
	if (n == 1) {
		if(k%2 == 0)
			cout << v[0] << endl;
		else {
			cout << missing << endl;
		}
		return;
	}

	v.push_back(missing);
	int sft = k % (n + 1);
	//cout << missing << endl;
	for (int i = -sft; i < -sft + n; i++) {
		if (i < 0) {
			cout<<v[n + i + 1] << " ";
		}
		else {
			cout << v[i] << " ";
		}
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