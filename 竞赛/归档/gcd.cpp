#include <iostream>
#define ll long long 
using namespace std;
ll a, b;

inline ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    cin >> a >> b;
    cout << gcd(a, b);
    // cout << (-8) % 3;
}