#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include <iostream>

using namespace std;
char name[] = "12345678";
const int MAX = 10;
char path[MAX];
int target, depth;
bool ascending(char s[]) {
	for (int i = 0; i < strlen(s)-1; i++) {
		if (s[i] > s[i + 1]) {
			return false;
		}
	}
	return true;
}

void print(char s[]) {
	for (int i = 0; i < MAX; i++) {
		if (s[i] == '\0') {
			return;
		}
		else {
			cout << s[i] << " ";
		}
	}
}

void rec(int level) {
	if (level == target) {
		if (ascending(path)) {
			print(path);
			cout << endl;
		}
		
		return;
	}
	for (int i = 0; i < depth; i++) {
		path[level] = name[i];
		rec(level + 1);
		path[level] = 0;
	}
}

int main() {
	cin >> depth;
	cin>> target;

	rec(0);
}