#include <iostream>

using namespace std;
int n, dp[201][201], a[301];

void dp_func(){
    int r;
    for(int i=1;i<2*n;i++)
        for (int j=1;j<2*n;j++)
            dp[i][j] = 0;
    for(int len=1;len<n;len++){    // 2
        for(int l=1;l+len-1<=2*n;l++){  // !!!重要:不能写成l<=n,虽然答案与此无关但必须要更新
            r = l + len;
            for(int k=l;k<r;k++){   // +1
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r] + a[l] * a[k+1] * a[r+1]);
                // cout <<"l "<<l<<" k "<<k<<" r "<<r<<" val "<<dp[l][r]<<" a "<<a[l] * a[k+1] * a[r+1]<<" ori_val "<<dp[l][k]<< " " << dp[k+1][r]<<endl;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i+n]=a[i];
        a[i+n+n]=a[i];
    }
    dp_func();
    int r, e=0;
    for(int l=1;l<=n;l++){
        r = l + n-1;
        e = max(e, dp[l][r]);
    }
    cout << e;
    return 0;
}