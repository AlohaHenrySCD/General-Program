#include <iostream>
#include <vector>
using namespace std;
const int MAXN=1e5+5;
int n, p[MAXN];
using LL = long long;
LL dp[MAXN], smax=0;
bool leaf[MAXN];
vector<int> g[MAXN];
bool vis[MAXN];
LL ans;

void dfs(int i) {
    vis[i] = 1;
    for (int u : g[i]) {
        if (!vis[u]) {
            dfs(u);
            dp[i] = max(dp[i], dp[i] + dp[u]);
        }
    }
    ans = max(ans, dp[i]);
}
/*
void dp_func(int leaf){
    for(int i=leaf;p[i]!=0;i=p[i]){
        dp[p[i]] = max(dp[p[i]], dp[p[i]]+dp[i]);
        smax = max(smax, dp[p[i]]);
        // for (int j=1;j<=n;j++) cout << dp[j] << ' ';
        // cout << endl;
    }
}
*/

int main(){
    int u, v;   // from u to v
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> dp[i];
    }
    for (int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}