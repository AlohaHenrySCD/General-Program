#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Nmax = 505;
int n, k;
string s;
int f[Nmax][Nmax], g[Nmax][Nmax], h[Nmax][Nmax];

int main(){
    cin >> n >> k >> s;
    int r;
    for(int i=1;i<=n;i++){ // r = l+ i
        for(int l=0;l<n;l++){
            r = l + i;
            bool flag=0;
            if(i<k) for(int j=l,j<=)
        }
    }
    return 0;
}