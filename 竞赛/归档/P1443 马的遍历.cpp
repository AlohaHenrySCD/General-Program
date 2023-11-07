#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define _for(i, a, b) for(int i=(a);i<(b);i++)
#define _rep(i, a, b) for(int i=(a);i<=(b);i++)
#define pii pair<int, int>
// #define mp(a, b) make_pair((a), (b))
using namespace std;
const int Nmax = 405;
int n, m, x, y, t;
int ches[Nmax][Nmax];

struct th{
    int f, s, t;
};
queue<th> q;

inline th mth(int f, int s, int t){
    th e = {f, s, t};
    return e;
}

void bfs(){
    // ches[x][y] = 0;
    q.push(mth(x, y, 0));
    while(!q.empty()){
        x = q.front().f;
        y = q.front().s;
        t = q.front().t;
        q.pop();
        // cout << x << y << t << endl;
        if(!(x>=1&&x<=n&&y>=1&&y<=m)||ches[x][y]!=-1) continue;
        ches[x][y] = t;
        for(int k=-1; k<=1;k+=2) _rep(i, 1, 2){
            int j = 3-i;
            q.push(mth(x+k*i, y-k*j, t+1));
            q.push(mth(x+k*i, y+k*j, t+1));
        }
    }
}

int main(){
    memset(ches, -1, sizeof(ches));
    cin >> n >> m >> x >> y;
    bfs();
    _rep(i, 1, n){
        _rep(j, 1, m)
            cout << ches[i][j] << ' ';
        cout << endl;
    }
}