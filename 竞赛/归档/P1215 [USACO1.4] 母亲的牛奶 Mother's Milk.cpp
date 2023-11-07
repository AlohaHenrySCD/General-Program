#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool ans[21];
bool vis[21][21][21]; // a b = c
int ma, mb, mc;

void dfs(int a, int b, int c){//shi ji
    if(vis[a][b][c]) return;
    vis[a][b][c] = true;
    // printf("a %d b %d c %d\n", a, b, c);
    if(a==0) ans[c] = true;
    if(a+b<mb)  dfs(0, a+b, c);
    else        dfs(a+b-mb, mb, c);
    if(a+b<ma)  dfs(a+b, 0, c);
    else        dfs(ma, a+b-ma, c);
    if(a+c<mc)  dfs(0, b, a+c);
    else        dfs(a+c-mc, b, mc);
    if(a+c<ma)  dfs(a+c, b, 0);
    else        dfs(ma, b, a+c-ma);
    if(b+c<mc)  dfs(a, 0, b+c);
    else        dfs(a, b+c-mc, mc);
    if(b+c<mb)  dfs(a, b+c, 0);
    else        dfs(a, mb, b+c-mb);
}

int main(){
    cin >> ma >> mb >> mc;
    dfs(0, 0, mc);
    for(int i=0;i<=20;i++){
        if(ans[i]==true) cout << i << ' ';
    }
}