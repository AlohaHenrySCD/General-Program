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
const int Nmax = 1e5+5;
int t, n, m;
bool b[Nmax];

struct el{
    int v, pos;
} a[Nmax];
bool cmp(el a, el b){
    return a.v < b.v ? 1 : a.pos < b.pos;
}

int main(){
    cin >> t;
    _for(i, 0, t){
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        _for(j, 0, n)
            cin >> a[j].v, a[j].pos = j;
        sort(a, a+n, cmp);
        int cnt=1;
        el pre = a[0];
        _for(j, 1, n){
            if(pre.v==a[j].v)
                cnt++;
            else if(cnt==1)
                b[pre.pos] = 1;
            else
                cnt = 1;
            pre = a[j];
        }
        if(a[n-1].v!=a[n-2].v) b[a[n-1].pos] = 1;
        _for(j, 0, n){
            cout << b[j] << ' ';
        }
    }
    return 0;
}