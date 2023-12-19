#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include<algorithm>
#define endl '\n'
using namespace std;
const int dy[]={0,0,1,-1}, dx[] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int ans = 0;
        int n,k;
        cin>>n>>k;
        vector<int>an(n);
        vector<int>bn(n);
        for(int i = 0 ; i < n ; i++){
            cin>>an[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>bn[i];
        }
        int maxval = 0;
        int temp = 0;
        for(int i = 0 ; i < min(n,k); i++){
            maxval = max(maxval, bn[i]);
            temp += an[i];
            ans = max(ans, temp+maxval*(k-i-1));
        }
        cout<<ans<<endl;
    }
}