#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> v1, v2;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		v1.clear(); v2.clear();
		int arr[4][1001];
		int k, n;
		cin >> k >> n;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		//v1에는 class 1,2에서 가능한 몸무게 합 모든 경우의 수가, v2에는 class 3,4가 들어간다
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v1.push_back(arr[0][i] + arr[1][j]);
				v2.push_back(arr[2][i] + arr[3][j]);
			}
		}
		//이분탐색을 위해 정렬
		sort(v2.begin(), v2.end());
		int ans = INT32_MAX;
		for (auto a : v1) {
			int index = lower_bound(v2.begin(), v2.end(), k - a) - v2.begin();
			//lower_bound 수행시 만족하는 값이 없으면 v2.end()를 리턴하기 때문에 이 경우에 대해 continue 시 오답이라 -1한 값을 탐색해주니 정답처리됨
			if (index == n * n)
				index--;
			if (abs(k - ans) > abs(k - a - v2[index]))
				ans = a + v2[index];
			if (index > 0 && abs(k - ans) >= abs(k - a - v2[index - 1]))
				ans = a + v2[index - 1];
		}
		cout << ans << '\n';
	}

}