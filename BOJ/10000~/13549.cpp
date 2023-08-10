#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 200001;

void findsis(int N, int K) {
	int arr[MAX] = { 0 };
	queue<int> q;
	q.push(N);
	arr[N] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (t == K)
			break;
		if (t != 0) {
			for (int i = t; i < MAX; i *= 2) {
				if (arr[i] == 0) {
					arr[i] = arr[t];
					q.push(i);
				}
			}
			if (t - 1 >= 0 && arr[t - 1] == 0) {
				arr[t - 1] = arr[t] + 1;
				q.push(t - 1);
			}
			if (t + 1 < MAX && arr[t + 1] == 0) {
				arr[t + 1] = arr[t] + 1;
				q.push(t + 1);
			}
		}
		else {
			arr[1] = arr[0] + 1;
			q.push(1);
		}
	}
	cout << arr[K]-1;
}

int main() {
	int N, K;
	cin >> N >> K;
	findsis(N, K);
}