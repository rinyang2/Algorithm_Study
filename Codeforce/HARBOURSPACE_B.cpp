#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	if (k % 2 == 0) {
		sort(s.begin(), s.end());
		cout << s<<endl;
		return;
	}

	string s1, s2;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0)
			s1.push_back(s[i]);
		else
			s2.push_back(s[i]);
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	string answer;
	bool b = true;
	int i = 0, j = 0;
	while(i != s1.size() || j!= s2.size()) {
		if (b)
			answer.push_back(s1[i++]);
		else
			answer.push_back(s2[j++]);
		b = !b;
	}
	cout << answer << endl;
}



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
        solve();
	}
}