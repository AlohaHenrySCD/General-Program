#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5+3;
int n, a[N], flag;

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n, greater<int>());
    int b = unique(a, a+n) - a - 1;
    if(b==1) cout << -1;
    else cout << max(a[2], a[0]%a[1]);
}