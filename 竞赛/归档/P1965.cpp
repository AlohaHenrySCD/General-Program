#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll n, m, k, x;

ll qpow(ll a, ll b, ll p){
    ll ret = 1;
    while(b){
        if(b&1) ret = (ret * a) %p;
        a = (a*a)%p, b >>=1;
    }
    return ret;
}

int main(){
    cin >> n >> m >> k >> x;
    cout << (qpow(10, k, n)*m + x) %n;
}