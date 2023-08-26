#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl '\n'

void solution() {
	int N, M;
	cin >> N >> M;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	string temp = "";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (v[j][i] == 'v' && temp.length() == 0) {
				temp += 'v';
				break;
			}
			if (v[j][i] == 'i' && temp.length() == 1) {
				temp += 'i';
				break;
			}if (v[j][i] == 'k' && temp.length() == 2) {
				temp += 'k';
				break;
			}if (v[j][i] == 'a' && temp.length() == 3) {
				temp += 'a';
				break;
			}
		}
	}
	if (temp == "vika") {
		cout << "YES"<<endl;
	}
	else {
		cout << "NO"<<endl;
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solution();
	}
}