#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;



int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	if (v.back() < 0) {
		cout << v[v.size() - 2] << " " << v[v.size() - 1];
		return 0;
	}

	//sort(v.begin(), v.end());
	int lp = 0;
	int anslp = 0, ansrp = 1;
	int minval = INT32_MAX;
	while (v[lp] < 0 && lp<N) {
		int temp = upper_bound(v.begin(), v.end(), -v[lp]) - v.begin();
		
		int comp;
		if (temp == N) {
			comp = abs(v[lp] + v[temp - 1]);
			if (minval>comp) {
				minval = comp;
				anslp = lp;
				ansrp = temp - 1;
			}
		}
			
		else {
			if (abs(v[lp] + v[temp]) > abs(v[lp] + v[temp - 1]) && lp != temp-1) {
				comp = abs(v[lp] + v[temp - 1]);
				if (minval > comp) {
					minval = comp;
					anslp = lp;
					ansrp = temp - 1;
				}
			}
			else {
				comp = abs(v[lp] + v[temp]);
				if (minval > comp) {
					minval = comp;
					anslp = lp;
					ansrp = temp;
				}
			}
		}	
			
		lp++;
	}
	cout << v[anslp] << " " << v[ansrp];
}