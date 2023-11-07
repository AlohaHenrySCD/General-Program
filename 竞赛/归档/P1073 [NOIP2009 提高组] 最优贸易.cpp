#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1e5+1, MAXM = 5e5+1;
int val[MAXN], minval[MAXN], dp[MAXN];
int n, m;
vector<int> g[MAXN];

void dfs(int u){
    int predp, premv;
    for(auto v : g[u]){
        predp = dp[v];
        premv = minval[v];
        minval[v] = min(val[v], minval[u]);
        dp[v] = max(dp[v], dp[u]);
        dp[v] = max(dp[v], val[v] - minval[v]);
        // for(int i=1;i<=n;i++) cout << dp[i] << ' ';
        // cout << endl;
        if(!(predp==dp[v]) || !(premv==minval[v])){
            dfs(v);
        }
    }
}


int main(){
    int x, y, z;
    cin >> n >> m;
    memset(minval, 0x3f, sizeof(minval));
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }
    for(int i=1;i<=m;i++){
        cin >> x >> y >> z;
        g[x].push_back(y);
        if(z==2) g[y].push_back(x);
    }
    g[0].push_back(1);
    dfs(0);
    cout << dp[n];
    return 0;
}