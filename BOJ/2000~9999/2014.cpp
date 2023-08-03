#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	long long target = 0;
	priority_queue <long long, vector<long long>, greater<long long>> pq;
	int K, N;
	cin >> K >> N;
	int arr[100];
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	for (int i = 0; i < N; i++) {
		long long t = pq.top();
		while (!pq.empty() && t == pq.top()) {
			pq.pop();
		}
		for (int j = 0; j < K; j++) {
			long long r = t * arr[j];
			if (r >= INT32_MAX)
				break;
			pq.push(r);
			if (t%arr[j] == 0)
				break;
		}
		target = t;
	}
	cout << target;
}