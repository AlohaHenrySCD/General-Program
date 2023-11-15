#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6+5;
int n, s[N][2], pa[N], w[N], siz[N], vis[N];

void back(int i){
    if(vis[i]||i==0) return;
    vis[i] = true;
    back(pa[i]);
}

int cal_siz(int i){
    int si=1;
    if(s[i][0]!=-1) si += cal_siz(s[i][0]);
    if(s[i][1]!=-1) si += cal_siz(s[i][1]);
    return siz[i] = si;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> s[i][0] >> s[i][1];
        if(s[i][0]!=-1) pa[s[i][0]] = i;
        if(s[i][1]!=-1) pa[s[i][1]] = i;
    }
    for(int i=1;i<=n;i++)
        if(w[s[i][1]]!=w[s[i][0]])
            back(i);
    cal_siz(1);
    int ans = 0;
    for(int i=1;i<=n;i++)
        if(!vis[i]) ans = max(ans, siz[i]);
    cout << ans;
}