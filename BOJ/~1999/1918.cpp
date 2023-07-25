#include <iostream>

using namespace std;

const int MAX = 101;
//return length of a string
int len(char arr[]) {
	for (int i = 0; i < MAX; i++) {
		if (arr[i] == '\0') {
			return i;
		}
	}
}
//pop stack and return
char pop(char arr[]) {
	int l = len(arr);
	char c = arr[l - 1];
	arr[l - 1] = '\0';
	return c;
}
//append element to stack
void append(char arr[], char c) {
	int l = len(arr);
	arr[l] = c;
	arr[l + 1] = '\0';
}
//return top value of stack
char top(char arr[]) {
	if (len(arr) == 0) {
		return 'X';
	}
	return arr[len(arr) - 1];
}
bool isUpAlph(char c) {
	if (c >= 'A' && c <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}
void flush(char arr[]){
	while (true) {
		char t = pop(arr);
		if (t == '(') {
			break;
		}
		cout << t;
		if (len(arr) == 0) {
			break;
		}
	}
}

int main()
{
	char input[MAX];
	char stack[MAX]="";
	cin >> input;
	int length = len(input);
	for (int i = 0; i < length; i++) {
		//cout << "\n "<<input[i]<<" current stack: " << stack << endl;
		if (isUpAlph(input[i])) {
			cout << input[i];
		}
		else if (input[i] == '(') {
			append(stack,input[i]);
		}
		else if (input[i] == ')') {
			while (true) {
				char c = pop(stack);
				if (c == '(') {
					break;
				}
				cout << c;
			}
		}
		else if (input[i] == '*' || input[i] == '/') {
			char t = top(stack);

			if (t == '*' || t == '/') {
				cout << pop(stack);
				append(stack, input[i]);
			}

			else {
				append(stack, input[i]);
			}
			
		}
		else if (input[i] == '+' || input[i] == '-') {
			char t = top(stack);
			if (t == '*' || t == '/') {
				while (true) {
					char q = pop(stack);
					if (q == '(') {
						append(stack, q);
						break;
					}
					cout << q;
					if (len(stack) == 0) {
						break;
					}
				}
				append(stack, input[i]);
			}
			else if (t == '+' || t == '-') {
				cout << pop(stack);
				append(stack, input[i]);
			}
			else {
				append(stack, input[i]);
			}
		}
	}
	while (len(stack) > 0) {
		cout << pop(stack);
	}
}