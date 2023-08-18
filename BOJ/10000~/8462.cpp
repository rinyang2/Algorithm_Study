#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//mo's 알고리즘 이용하는 문제
int DAT[1000001] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n>>m;

    //long long 을 써야 오버플로우가 안난다
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    //쿼리를 우선 정렬을 할 것이기 때문에 인덱스를 따로 저장해준다
    vector<pair<pair<int, int>, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    //mo's 알고리즘
    //제곱근 분할법으로 정렬해서 쿼리를 수행해야한다
    int sq = sqrt(n);
    sort(queries.begin(), queries.end(), [sq](const auto& a, const auto& b) {
        int block_a = a.first.first / sq;
        int block_b = b.first.first / sq;
        if (block_a != block_b) {
            return block_a < block_b;
        }
        return a.first.second < b.first.second;
        });
    //long long 을 써야 오버플로우가 안난다
    long long cnt = 0;
    int lp = queries[0].first.first - 1;
    int rp = queries[0].first.second - 1;
    //cout << lp << " " << rp << endl;
    for (int i = lp; i <= rp; ++i) {
        cnt += arr[i] * (2*DAT[arr[i]] + 1);
        DAT[arr[i]]++;
    }
    //long long 을 써야 오버플로우가 안난다
    vector<long long> result(m);
    result[queries[0].second] = cnt;
    //투포인터를 이용한 쿼리 수행
    for (int i = 1; i < m; ++i) {
        int l = queries[i].first.first - 1;
        int r = queries[i].first.second - 1;
        //포인터의 증감 순서 중요함!
        //빼는 경우는 현재것을 빼고 다음 포인터로 이동하는거고
        //더하는 경우는 포인터를 증가시킨 후 다음것을 더하는것임
        //더하는 양은 2n+1 이고 빼는 양은 2n-1이다
        //(n+1)^2 - n^2 = 2n+1이니까
        while (lp < l) {
            cnt -= arr[lp] * (2 * DAT[arr[lp]] - 1);
            DAT[arr[lp]]--;
            lp++;
        }

        while (lp > l) {
            lp--;
            cnt += arr[lp] * (2 * DAT[arr[lp]] + 1);
            DAT[arr[lp]]++;
        }

        while (rp < r) {
            rp++;
            cnt += arr[rp] * (2 * DAT[arr[rp]] + 1);
            DAT[arr[rp]]++;
        }

        while (rp > r) {
            cnt -= arr[rp] * (2 * DAT[arr[rp]] - 1);
            DAT[arr[rp]]--;
            rp--;
        }
        //인덱스 순서대로 결과값 저장해준다
        result[queries[i].second] = cnt;
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}