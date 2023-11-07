#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
const int hour = 86400;
ll n, t, k, dif, x;
int tong[int(1e5+5)];
queue<pii> q;
vector<int> info[int(1e5+5)];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        cin >> k;
        pii top;
        while(!q.empty()&&t - q.front().first>=hour){
            top = q.front(); q.pop();
            for(auto e : info[top.second]){
                tong[e]--;
                if(!tong[e]) dif--;
            }
        }
        q.push(make_pair(t, i));
        for(int j=0;j<k;j++){
            cin >> x;
            info[i].push_back(x);
            if(!tong[x]) dif++;
            tong[x]++;
        }
        cout << dif << endl;
    }
    // pii top;
    // while(!q.empty()){
    //     top = q.front(); q.pop();
    //     cout << dif << endl;
    //     for(auto e : info[top.second]){
    //         tong[e]--;
    //         if(!tong[e]) dif--;
    //     }
    // }
    return 0;
}