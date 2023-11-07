#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define pii pair<int, int>
using namespace std;
int t, n, m, k, a, te, tee;
int ans;

int main(){
    cin >> t;
    _for(i, 0, t){
        cin >> n >> k;
        ans = 100;
        tee = 0; int et = 0;
        if(k!=4) _for(j, 0, n){
            cin >> a;
            te = a%k==0 ? 0 : k-a%k;
            // printf("te:%d ", te);
            ans = min(ans, te);
        } else _for(j, 0, n){
            cin >> a;
            // tee = tee + (a%2==0);
            if(a%2==0) tee++; else et++;
            if(tee>=2) ans=0;
            if(tee==1&&et>=1) ans = min(ans, 1);
            if(et>=2) ans = min(ans, 2);
            ans = min(ans, (a%4==0 ? 0 : k-a%4));
        }
        cout << ans << endl;
    }
    return 0;
}