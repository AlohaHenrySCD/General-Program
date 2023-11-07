#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX=3e5+1;
int n, k;
struct Task
{
    int pos;
    int val;
}a[NMAX];

bool cmp(Task a, Task b){
    return a.val < b.val;
}

int threads(){
    sort(a, a+n, cmp);
    int kk = k;
    int amin = foo(kk-1);
    while(a[kk-1].val == a[kk].val){
        amin = min(amin, foo(kk));
        kk++;
    }
    return amin;
}

int foo(int kk){// 0 to k-2 + "kk"
    int left=0, all, right, minval;
    // 排序回来？
    for(int i=0;i<k;i++){
        all += a
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i].val;
        a[i].pos = i;
    }
    cout << threads();
    return 0;
}