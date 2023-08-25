#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define endl '\n'
#define MAX 9999999
using namespace std;
int N;

//추의 정보를 담을 공간
vector<int> choo;

//임의의 값 n이 추의 조합으로 확인 가능한지 찾아줄 DAT
vector<bool> v;

//탐색한 값들을 중복 없이 넣어줄 공간
vector<int> temp;

int cnt = 0;

int main() {
	cin >> N;
	choo.resize(N);
	
	//추를 모두 입력받고, 그 총합을 구한다
	for (int i = 0; i < N; i++) {
		cin>>choo[i];
		cnt += choo[i];
	}
	//추의 총합만큼이 확인 가능한 최대의 무게이다
	v.resize(cnt + 1);


	for (int i = 0; i < N; i++) {
		int cn = choo[i];

		vector <int> asd;
		for (auto a : temp) {
			int l = abs(a - cn), r = a + cn;

			if (l<= cnt && v[l] == 0) {
				asd.push_back(l);
				v[l] = 1;
			}
			if (r <= cnt && v[r] == 0) {
				asd.push_back(r);
				v[r] = 1;
			}

		}
		for (auto a : asd) {
			temp.push_back(a);
		}
		if (v[cn] == 0) {
			v[cn] = 1;
			temp.push_back(cn);
		}
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int temp;
		cin >> temp;
		if (temp > cnt) {
			cout << "N ";
			continue;
		}
		if (v[temp]) {
			cout << "Y ";
		}
		else {
			
			cout << "N ";
		}
	}

}