#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll p = 1e9+7;
ll n, k;

ll qpow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b&1) ret = (ret * a)%p;
        b >>=1; a = (a*a)%p;
    }
    return ret;
}

int main(){
    cin >> n >> k;
    cout << qpow(2, n*k);

}