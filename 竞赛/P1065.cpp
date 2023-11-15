#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MN = 405;
int m, n, a[MN];
vector<int> mm[25];

struct B{
    int m, t;
}b[25][25];


int main(){
    cin >> m >> n;
    for(int i=1;i<=m*n;i++)
        cin >> a[i];
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++)
            cin >> b[j][i].m;
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++)
            cin >> b[j][i].t;
    
}