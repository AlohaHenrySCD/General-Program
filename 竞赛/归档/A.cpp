#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define pii pair<int, int>
using namespace std;
int t, x, y, k;

int f(int x){
    int ret=0;
    while(x){
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main(){
    cin >> t;
    _for(iter, 0, t){
        cin >> x >> k;
        int dis = f(x)%k ? k - f(x)%k : 0;
        while(dis+x%10>=10){
            x += 10-x%10;
            dis = f(x)%k ? k - f(x)%k : 0;
        }
        cout << x + dis << endl;
    }
    return 0;
}