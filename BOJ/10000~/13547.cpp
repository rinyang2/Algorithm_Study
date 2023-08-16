//solved with python, converted to c++ using chagGPT
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100001;
int DAT[1000001] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    vector<pair<pair<int, int>, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    int sq = sqrt(n);
    sort(queries.begin(), queries.end(), [sq](const auto& a, const auto& b) {
        int block_a = a.first.first / sq;
        int block_b = b.first.first / sq;
        if (block_a != block_b) {
            return block_a < block_b;
        }
        return a.first.second < b.first.second;
        });

    int cnt = 0;
    int lp = queries[0].first.first - 1;
    int rp = queries[0].first.second - 1;
    for (int i = lp; i <= rp; ++i) {
        DAT[arr[i]]++;
        if (DAT[arr[i]] == 1) {
            cnt++;
        }
    }

    vector<int> result(m);
    result[queries[0].second] = cnt;

    for (int i = 1; i < m; ++i) {
        int l = queries[i].first.first - 1;
        int r = queries[i].first.second - 1;

        while (lp < l) {
            DAT[arr[lp]]--;
            if (DAT[arr[lp]] == 0) {
                cnt--;
            }
            lp++;
        }

        while (lp > l) {
            lp--;
            DAT[arr[lp]]++;
            if (DAT[arr[lp]] == 1) {
                cnt++;
            }
        }

        while (rp < r) {
            rp++;
            DAT[arr[rp]]++;
            if (DAT[arr[rp]] == 1) {
                cnt++;
            }
        }

        while (rp > r) {
            DAT[arr[rp]]--;
            if (DAT[arr[rp]] == 0) {
                cnt--;
            }
            rp--;
        }

        result[queries[i].second] = cnt;
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
