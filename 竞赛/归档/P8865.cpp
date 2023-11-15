#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e3+5;
const ll p = 998244353;
int T, id;
int n, m, cs, fs, b[N][N], dis[N][N], ver[N][N];

int vis(int i, int j){
    if(j>m) return 0;
    if(b[i][j]){
        vis(i, j+1);
        return dis[i][j] = 0;
    }
    return dis[i][j] = vis(i, j+1) + 1;
}

int vis2(int i, int j){
    if(i>n) return 0;
    if(b[i][j]){
        vis2(i+1, j);
        return ver[i][j] = 0;
    }
    return ver[i][j] = vis2(i+1, j) + 1;
}

int main(){
    cin >> T >> id;
    for(int t=0;t<T;t++){
        cin >> n >> m >> cs >> fs;
        memset(dis, 0, sizeof(dis));
        memset(ver, 0, sizeof(ver));
        memset(b, 0, sizeof(b));
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++)
                b[i][j] = getchar()=='0' ? 0 : 1;
        }
        for(int i=1;i<=n;i++) vis(i, 1);
        for(int i=1;i<=m;i++) vis2(1, i);
        ll c=0, f=0;
        for(int j=1;j<=m;j++){
            int cnt=0, k=0;
            for(int i=1;i<=n;i++){
                if(b[i][j]){
                    cnt = 0; k = 0;
                } else {
                    cnt++;
                    k += dis[i][j] -1;
                    if(cnt<3) continue;
                    // printf("i %d j %d\n", i, j);
                    c = (c + 1ll * (dis[i][j]-1) * (k-dis[i][j]-dis[i-1][j]+2))%p;
                    f = (f + 1ll * ((dis[i][j]-1) * (ver[i][j]-1))%p * (k-dis[i][j]-dis[i-1][j]+2))%p;
                }
            }
        }
        cout << (cs * c)%p << ' ' << (fs * f)%p << endl;
    }
}