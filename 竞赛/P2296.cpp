#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
const int N = 1e4+5;
vector<int> g[N], h[N];
priority_queue<pii, vector<pii>, less<pii>> q;
int gsiz[N];
bool vis[N];
int dis[N];
int n, m, x, y, s, t;

void back(int i){
    if(gsiz[i]!=0)
        return;
    vis[i] = 1;
    for(auto j : h[i])
        gsiz[j]--, back(j);
}

void dij(){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; vis[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : g[u]){
            if(dis[v]>dis[u]+1)
                dis[v] = dis[u]+1; q.push(make_pair(dis[v], v));
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        g[x].push_back(y); h[y].push_back(x);
    }
    for(int i=1;i<=n;i++) gsiz[i] = g[i].size();
    cin >> s >> t;
    for(int i=1;i<=n;i++){
        if(g[i].empty()&&i!=t){
            back(i);
        }
    }
    dij();
    cout << (dis[t]==0x3f3f3f3f ? -1 : dis[t]);
}