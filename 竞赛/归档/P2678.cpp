#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5e4+5;
int l, r, n, m, d[N];
int mid=1, cnt, ans;


int main(){
    cin >> r >> n >> m;
    d[0] = 0; d[n+1] = r;
    for(int i=1;i<=n;i++)
        cin >> d[i];
    while(l<r){
        mid = (l+r)>>1;
        cnt = 0;
        for(int i=1;i<=n+1;i++){
            for(int j=1; d[i]-d[i-j]<mid&&i<=n+1; cnt++, i++, j++);
        }
        if(cnt>m) r = mid;
        else l = mid+1;
    }
    cout << l;
}