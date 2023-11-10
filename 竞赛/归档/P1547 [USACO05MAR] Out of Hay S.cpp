#include <iostream>
#include <cstdio>
#include <algorithm>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const int N = 2e3+5, M=1e4+5;
int n, m, res;
int pa[N], siz[N];

struct edge{
    int u, v, w;
}a[M];

int find(int i){
    return pa[i] == i ? i : pa[i] = find(pa[i]);
}

void unite(int f, int s){
    int x = find(f), y = find(s);
    if(x==y)
        return;
    if(siz[x] < siz[y]) swap(x, y);
    pa[y] = x;
    siz[x] += y;
    return;
}

bool cmp(edge a, edge b){
    return a.w<b.w;
}

void kru(){
    sort(a, a+m, cmp);
    _for(i, 0, m){
        if(find(a[i].u)==find(a[i].v)) continue;
        unite(a[i].u, a[i].v);
        res = a[i].w;
    }
}

int main(){
    cin >> n >> m;
    int u, v, w;
    _for(i, 0, n){
        pa[i] = i;
        siz[i] = 1;
    }
    _for(i, 0, m){
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    kru();
    cout << res;
    return 0;
}