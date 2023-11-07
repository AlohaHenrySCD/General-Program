#include <iostream>
using namespace std;
const int MAXN=1e5+1;
int dp[MAXN], dp2[MAXN], a[MAXN], n, ans1=1, ans2=1;

void dpfunc(){
    dp[1]=1;
    dp2[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp2[i] = 1;
        for(int k=1;k<i;k++){
            // 不上升就好？
            if(a[k]>=a[i]){
                dp[i] = max(dp[k]+1, dp[i]);
                ans1 = max(ans1, dp[i]);
            }
            if(a[k]<a[i]){
                dp2[i] = max(dp2[i], dp2[k]+1);
                ans2 = max(ans2, dp2[i]);
            }
        }
        // for (int j=1;j<=n;j++) cout << dp[j] << " ";
        // cout << endl;
    }
}

int main(){
    // 最长上升/下降子序列
    int flag=1;
    n = 0;
    while (cin>>a[++n]);n--;
    dpfunc();
    cout << ans1 << endl << ans2;
    return 0;
}