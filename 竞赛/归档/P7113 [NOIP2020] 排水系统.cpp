#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define ll unsigned long long
#define PLL pair<ll, ll>
using namespace std;
const int MAXN = 1e5+5;
int n, m, in[MAXN], out[MAXN];
PLL ans[MAXN];
vector<int> g[MAXN];
queue<int> q;

inline ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

void add(PLL &u, PLL &v, int ou){
    if(v.second == 0){
        v.first = u.first;
        v.second = u.second * ou;
        return; 
    }
    ll fir = u.first * v.second + v.first * u.second * ou;
    ll sec = u.second * ou * v.second;
    ll thr = gcd(fir, sec);
    v.first = fir/thr;
    v.second = sec/thr; 
}

void sort(){
    for(int i=1;i<=n;i++) if(in[i]==0){
        q.push(i);
        ans[i].first = 1; ans[i].second = 1;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            add(ans[u], ans[v], out[u]);
            if(--in[v] == 0)
                q.push(v);
        }
    }
}


int main(){
    cin >> n >> m;
    int d, ot;
    for(int i=1;i<=n;i++){
        cin >> d;
        out[i] = d;
        for(int j=0;j<d;j++){
            cin >> ot;
            in[ot]++;
            g[i].push_back(ot);
        }
    }
    sort();
    for(int i=1;i<=n;i++)   if(out[i]==0){
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    }
}