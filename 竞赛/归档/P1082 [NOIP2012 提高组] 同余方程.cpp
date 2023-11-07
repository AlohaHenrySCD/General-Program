#include <iostream>
#define ll long long
using namespace std;
// gcd(a, b) = 1
ll a, b, x, y;

void exgcd(ll a, ll b){
    if(b==0){
        x = 1;
        y = 0;
        return;
    } else {
        exgcd(b, a % b);
        ll xx = x;
        x = y;
        y = xx - (a/b) * y;
    }
}


int main(){
    cin >> a >> b;
    exgcd(a, b);
    x = ((x % b) + b) % b;
    cout << x;
}