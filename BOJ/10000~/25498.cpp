#include <iostream>
#include <queue>
#include <string>
#include<algorithm>
#define endl '\n'
using namespace std;

//struct box to store and sort
struct box{
    char c;
    int idx;
    //operator overloading for sort, desc
    bool operator<(const box b) const{
        return c>b.c;
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //input part
    int N;
    vector<vector<int>> v;
    string s;
    cin>>N;
    cin>>s;
    v.resize(N+1);
    for(int i = 0; i<N-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> visited(N+1);
    vector<char> ans;

    //always start from first node, initialize
    ans.push_back(s[0]);
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1] = 1;

    while(!q.empty()){
        //pair <node, depth>
        pair<int,int> now = q.front(); q.pop();
        vector<pair<int,int>> vp;
        vp.push_back(now);
        //pop all node that has same depth and store in vector "vp"
        while(q.front().second == now.second){
            vp.push_back(q.front());
            q.pop();
        }

        //push every child node to vector temp and sort
        vector<box> temp;
        for(auto a: vp){
            for(auto b: v[a.first]){
                if(visited[b]==0){
                    temp.push_back({s[b-1], b});
                    visited[b] = 1;
                }
            }
        }
        sort(temp.begin(), temp.end());

        //if there is no child, continue
        if(temp.size()==0)
            continue;
        //add biggest child to answer
        ans.push_back(temp[0].c);
        //push every node that has same child value
        for(auto a: temp){
            if(a.c == temp[0].c){
                q.push({a.idx,now.second+1});
            }
        }     
    }
    //output part
    for(auto a: ans){
        cout<<a;
    }
}