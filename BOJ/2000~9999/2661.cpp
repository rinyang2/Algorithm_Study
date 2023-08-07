#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 81;
int N;
char s[MAX];

bool valid(char s[], int level) {
	int length = level;
	//배열을 1부터 길이의 절반사이즈까지 i단위씩 잘라볼 겁니다
	for (int i = 1; i <= length / 2; i++) {
		//배열을 i단위로 자를건데 각 단위배열 첫 index가 j입니다
		for (int j = 0; j < length - i * 2 + 1; j += 1) {
			bool t = true;
			for (int k = 0; k < i; k++) {
				//단위 배열 중 하나라도 불일치하면 break
				if (s[j + k] != s[j + i + k]) {
					t = false;
					break;
				}
			}
			//두 부분배열이 일치하는 경우 false리턴
			if (t) {
				return false;
			}
		}
	}
	return true;
}

void good(int level) {

	if (level == N) {
		if (valid(s, level)) {
			cout << s << endl;
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (s[level - 1] == char('0' + i)) {
			continue;
		}
		s[level] = '0' + i;
		if (valid(s, level))
			good(level + 1);
	}
}

int main() {
	cin >> N;
	good(0);
}