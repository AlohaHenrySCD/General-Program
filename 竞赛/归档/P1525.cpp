#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1e5+5;
int n, m, pa[M], siz[M], ene[M];
struct edge{
    int u, v, w;
}e[M];

inline bool cmp(edge a, edge b){
    return a.w > b.w;
}

inline int find(int x){
    return pa[x]==x ? x : pa[x] = find(pa[x]);
}
void unite(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return;
    if(siz[x] < siz[y]) swap(x, y);
    pa[y] = x;
    siz[x] += siz[y];
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e+m, cmp);
    for(int i=0;i<M;i++) pa[i] = i, siz[i] = 1;
    for(int i=0;i<=m;i++){
        if(find(e[i].u)==find(e[i].v)){cout << e[i].w; break;}
        if(ene[e[i].u]) unite(ene[e[i].u], e[i].v);
        else ene[e[i].u] = e[i].v;
        if(ene[e[i].v]) unite(ene[e[i].v], e[i].u);
        else ene[e[i].v] = e[i].u;
    }
}
