#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int Nmax = 1e3+5;
struct Hole{
    ll x, y, z;
}h[Nmax];
ll t, n, hei, r;
ll srt[Nmax], ed[Nmax], scnt, ecnt;
ll pa[Nmax], siz[Nmax];

inline bool touch(Hole a, Hole b, ll r){
    double dis = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
    return dis <= double(2*r);
}

inline ll find(ll x){
    return pa[x] == x ? x : pa[x] = pa[x] = find(pa[x]);
}

void unite(ll x, ll y){
    x = find(x); y = find(y);
    if(x==y) return;
    if(siz[x] < siz[y]) swap(x, y);
    pa[y] = x;
    siz[x] += siz[y];
}

int main(){
    cin >> t;
    _for(i, 0, t){
        memset(srt, 0, sizeof(srt));
        memset(ed, 0, sizeof(ed));
        scnt = 0; ecnt = 0;
        cin >> n >> hei >> r;
        _for(j, 0, n)
            pa[j] = j, siz[j] = 1;
        _for(j, 0, n){
            cin >> h[j].x >> h[j].y >> h[j].z;
            if(h[j].z<=r) srt[scnt++] = j;
            if(h[j].z>=hei-r) ed[ecnt++] = j;
        }
        _for(j, 0, n) _for(k, 0, n){
            if(touch(h[j], h[k], r))
                unite(j, k);
        }
        bool flag=0;
        _for(j, 0, scnt) _for(k, 0, ecnt){
            if(find(srt[j])==find(ed[k])){
                flag = 1;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}