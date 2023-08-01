#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int D(int n) {
	return (n * 2) % 10000;
}
int S(int n) {
	if (n == 0) {
		return 9999;
	}
	else {
		return n - 1;
	}
}
int L(int n) {
	return (n * 10) % 10000 + (n / 1000);
}
int R(int n) {
	return (n % 10) * 1000 + n / 10;
}

void unlock(int from, int target) {
	string visited[10000];
	for (int i = 0; i < 10000; i++) {
		visited[i] = "";
	}
	queue <int> q;
	visited[from] = "\0";
	q.push(from);
	while (!q.empty()) {
		int x = q.front();
		if (x == target) break;
		q.pop();
		int arr[] = {D(x), S(x), L(x), R(x)};
		char s[] = "DSLR";
		for (int i = 0; i < 4; i++) {
			if (arr[i] != x && visited[arr[i]] == "") {
				q.push(arr[i]);
				visited[arr[i]] = visited[x]+s[i];
			}
		}
	}
	cout << visited[target]<<endl;
}


int main() {
	int N;
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		unlock(a, b);
	}
}