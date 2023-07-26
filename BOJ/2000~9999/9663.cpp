#include <iostream>
using namespace std;
//n-queen Problem

//Set maximum size of chessboard
const int MAX = 15;
//variable to get input of size of chessboard
int board_size;
//variable to count valid positions
int cnt = 0;
//key: row, value: column
int chessboard[MAX] = { 0 };
//returns abs value of int
int abs(int n) {
	if (n < 0) {
		return n * (-1);
	}
	return n;
}
//check if current position is valid
bool valid(int n) {
	for (int i = 1; i < n; i++) {
		// if same column || same diagonal, invalid queen position
		if (chessboard[i] == chessboard[n] || abs(n - i) == abs(chessboard[i] - chessboard[n])) {
			return false;
		}
	}
	return true;
}

void n_queen(int level) {
	//if current node is valid
	if(valid(level)) {
		//if current node is maximum depth (valid position)
		if (level == board_size) {
			cnt++;
			return;
		}
		//check all column cases
		for (int j = 1; j <= board_size; j++) {
			chessboard[level + 1] = j;
			n_queen(level + 1);
		}
	}
}

int main() {
	cin >> board_size;
	n_queen(0);
	cout << cnt;
}