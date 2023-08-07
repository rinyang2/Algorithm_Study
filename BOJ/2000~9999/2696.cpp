#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		priority_queue <int, vector<int>, greater<int>> max_q;
			priority_queue <int> min_q;
			vector<int> answer;
			int N;
			cin >> N;
			int mid;
			cin >> mid;
			answer.push_back(mid);
			for (int i = 0; i < N/2; i++) {
				int A, B;
				cin >> A >> B;

				if (A > mid && B > mid) {
					max_q.push(A);
					max_q.push(B);
					min_q.push(mid);
					mid = max_q.top();
					max_q.pop();

				}
				else if (A < mid && B < mid) {
					min_q.push(A);
					min_q.push(B);
					max_q.push(mid);
					mid = min_q.top();
					min_q.pop();
				}
				else {
					if (A > B) {
						max_q.push(A);
						min_q.push(B);
					}
					else {
						max_q.push(B);
						min_q.push(A);
					}
				}
				answer.push_back(mid);
			}
			cout << answer.size()<<"\n";
			for (int i = 1; i <= answer.size(); i++) {
				cout << answer[i - 1] << " ";
				if (i % 10 == 0)
					cout << "\n";
			}
			cout << "\n";

	}
	


}
