#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const ll N = 2e5+5, K = 55;
ll n, k, p;
int a[N], b[N], l[N], s[K];

int main(){
    cin >> n >> k >> p;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i];
    int t = 1, ans = 0;
    for(int i=1;i<=n;i++){
        if(b[i]<=p){
            ans--;
            for(;t<=i;t++)
                s[a[t]]++;
        }
        ans += s[a[i]];
    }
    cout << ans;
}