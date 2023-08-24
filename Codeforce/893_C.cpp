#include <iostream>
#include <unordered_set>
using namespace std;
#define endl '\n'

void ans(int n) {
	unordered_set<int> us;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j *= 2) {
			auto index = us.find(j);
			if (index != us.end()) {
				break;
			}
			else {
				cout << j << " ";
				us.insert(j);
			}
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ans(n);
	}
}