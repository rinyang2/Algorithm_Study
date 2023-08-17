#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


struct asd{
	int a, b;
	int sum;
};





int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int arr[4][1001];
		int k, n;
		cin >> k >> n;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		vector<int> v1, v2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					v1.push_back(arr[0][i] + arr[1][j]);
					v2.push_back(arr[2][i] + arr[3][j]);
				}
			}
		}

	}
	
}