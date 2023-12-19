#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>
#include<set>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll c = n - 1;
        ll b = true;
        set<ll> s;
        for (int i = 0; i < k; i++) {
            if (s.count(c)) 
                break;
            if (v[c] > n) {
                b = false;
                break;
            }
            s.insert(c);
            c = (c - v[c] + n) % n;
        }
        cout << (b ? "YES" : "NO") << endl;
    }
}
