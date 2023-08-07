#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct st{
	int value;
	int index;
	bool operator<(st a) const {
		return value > a.value;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, L;
	cin >> N >> L;
	priority_queue <st> pq;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		pq.push({a,i});
		while (true) {
			if (pq.top().index >= i - L + 1)
				break;
			pq.pop();
		}
		cout << pq.top().value<<" ";
	}

}