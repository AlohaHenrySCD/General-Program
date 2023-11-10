#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define ll long long
#define pii pair<int, int>
using namespace std;
const ll A = 1e5+5;
ll a, b;

int main(){
    cin >> a >> b;
    if(a > b) swap(a, b);
    cout << (a-1)*b - a;
    return 0;
}