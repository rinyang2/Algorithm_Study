#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> lis;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
		if (index == lis.size())
			lis.push_back(v[i]);
		else {
			lis[index] = v[i];
		}
	}
	cout << lis.size();
}