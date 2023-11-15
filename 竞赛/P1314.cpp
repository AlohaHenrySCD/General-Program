#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 2e5+5;
int n, m;
ll s;
struct mtr{
    int w, v;
}a[N];
int b[N];
bool cmp(mtr a, mtr b){
    return a.w < b.w;
}

int main(){
    cin >> n >> m >> s;
    for(int i=0;i<n;i++)
        cin >> a[i].w >> a[i].v;
    // sort(a, a+n, cmp);
    // for(int i=1;i<n;i++)
    //     a[i].v += a[i-1].v;
    int l, r, mid;
    for(int i=0;i<m;i++){
        cin >> l >> r;
    } 
}