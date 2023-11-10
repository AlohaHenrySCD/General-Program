#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5+5;
int n, pa[N], dis[N], ans = N, v[N];

int find(int a){
    if(pa[a]==a) return a;
    int pre = pa[a];
    pa[a] = find(pa[a]);
    dis[a] += dis[pre];
    return pa[a];
}

void unite(int a, int b){
    int x = find(a), y = find(b);
    if(x==y) ans = min(ans, dis[b]+1);//最后一条边
    else pa[x] = y, dis[a] = dis[b]+1;//
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> v[i], pa[i] = i;
    for(int i=1;i<=n;i++){
        unite(i, v[i]);
    }
    // for(int i=0;i<n;i++) cout << pa[i] << ' ';
    cout << ans;
}