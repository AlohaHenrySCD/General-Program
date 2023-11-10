#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+5, H = 1e6+5;
int n, ans, a[N];

int find(int flag){
    int x = flag ? -1 : H;
    int ret = 0;
    for(int i=0;i<n-1;i++){
        if(a[i]>=x&&flag==1)
            ret += 2, flag=0, x = a[i];// printf("case1: i %d\n", i);
        else if(a[i]>=x&&flag==0) x = a[i];
        else if(x>a[i]) x = a[i], flag=1;
    }
    int i = n-1;
    if(a[i]>=x&&flag==1) ret += 2;
    else if(x>a[i]) ret+=1;
    return ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    ans = find(0);
    ans = max(ans, find(1)-1);
    cout << ans;
}