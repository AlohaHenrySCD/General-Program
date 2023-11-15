#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e6+5;
ll n, m, r[N], cf[N];
struct plan{
    ll d, s, t;
}p[N];

bool f(ll mid){
    memset(cf, 0, sizeof(cf));
    for(int i=1;i<=mid;i++){
        cf[p[i].s] += p[i].d;
        cf[p[i].t+1] -= p[i].d;
    }
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += cf[i];
        if(sum > r[i]) return false;
    }
    return true;
}


int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> r[i];
    for(int i=1;i<=m;i++)
        cin >> p[i].d >> p[i].s >> p[i].t;
    ll l=1, r=m, mid = (l+r)>>1;
    if(f(m)){
        cout << 0;
        return 0;
    }
    while(l<r){
        if(f(mid)){
            l = mid+1;
        }else{
            r = mid;
        }
        mid = (r+l)>>1;
    }
    cout << -1 << endl << l;
}