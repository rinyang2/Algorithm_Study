#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'

using namespace std;
vector<int>v;

int main() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int lp = 0, rp = N-1;
	int lval = v[lp], rval = v[rp];
	int sum = v[lp] + v[rp];
	while (lp < rp) {
		if (sum > 0) {
			rp--;
			if (lp == rp)
				break;
		}
		else if (sum < 0) {
			lp++;
			if (lp == rp)
				break;
		}
		else {
			break;
		}
		
		if (abs(v[lp] + v[rp]) < abs(lval+rval)) {
			lval = v[lp]; rval = v[rp];
		} 
		sum = v[lp] + v[rp];
	}
	cout << lval << " " << rval;

}