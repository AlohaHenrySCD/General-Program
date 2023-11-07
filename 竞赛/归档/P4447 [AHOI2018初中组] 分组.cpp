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
int n, a[100005];
int cnt = 0, m = 1e9+5;

int main(){
    cin >> n;
    _for(i, 0, n)
        cin >> a[i];
    sort(a, a+n, greater<int>());
    // _for(i, 0, n) cout << a[i] << ' ';
    _for(i, 1, n){
        if(a[i-1]-1==a[i]){
            cnt++;
        } else {
            m = min(m, cnt);
            cnt=1;
        }
    }
    cout << m;
    return 0;
}