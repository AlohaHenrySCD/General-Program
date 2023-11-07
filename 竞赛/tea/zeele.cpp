#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
// #define pii pair<int, int>
using namespace std;
const int Nmax = 1e6+5;
int n, m, al, bl, ar, br;
ll k;
int a[Nmax], b[Nmax];

int main(){
    freopen("zeele.in", "r", stdin);
#ifndef Test
    freopen("zeele.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a, a+n, greater<int>());sort(b, b+m, greater<int>());
    int ans;
    for(ll i=0;i<2*k;i++){
        // printf("al %d br %d ar %d bl %d\n", a[al], b[br], a[ar], b[bl]);
        if(a[al]+b[br]>=a[ar]+b[bl]){
            ans = a[al]+b[br];
            if(br>=m) al++, br=0;
            else br++;
        } else {
            ans = a[ar]+b[bl];
            if(ar>=m) bl++, ar=0;
            else ar++;
        }
    }
    cout << ans;
    return 0;
}