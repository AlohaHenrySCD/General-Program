#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>
#define ll __int128
#define pii pair<ll, ll>
using namespace std;
const ll N = 1e5+5, M = 15;
int n, m, d, ad, in[M];
vector<ll> g[M];
vector<ll> out;
queue<ll> q;
pii w[N];

inline ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

inline pii tongfen(ll a, ll b){
    ll g = gcd(a, b);
    return make_pair(a/g, b/g);
}

inline pii over(pii a, int b){
    return tongfen(a.first, a.second*b);
}

inline pii add(pii a, pii b){
    return tongfen(a.first*b.second+b.first*a.second, b.second*a.second);
}

void tuopu(){
    for(int i=1;i<=n;i++) if(!in[i])
        q.push(i), w[i].first = 1, w[i].second = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        pii ws = over(w[u], g[u].size());
        // printf("wsf %lld wss %lld\n", ws.first, ws.second);
        for(auto v : g[u]){
            in[v]--; if(!in[v]) q.push(v);
            w[v] = w[v].second!=0 ? add(w[v], ws) : ws;
        }
    }
}

void prt(ll n) {
    if(n > 9) prt(n / 10);
    putchar(n % 10 + 48);
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d;
        if(!d) out.push_back(i);
        for(int j=1;j<=d;j++){
            cin >> ad; g[i].push_back(ad);
            in[ad]++;
        }
    }
    tuopu();
    for(auto i : out){
        prt(w[i].first);putchar(' ');prt(w[i].second);putchar('\n');
    }
}