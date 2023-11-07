#include <iostream>
#include <algorithm>
using namespace std;
int l, s, t, m, ans;
int dp[(int) 1e4+5], ori[101];
bool a[(int) 1e4+5];
long s1=0, s2=0, s3=0; // s1 累加 s2 数据 s3 a数组位置

void dp_func(const int maxlen){
    if(l-s1 > maxlen) l=s1+maxlen;
    for(int i=1;i<=l;i++){
        if(i-s>=0) dp[i] = dp[i-s];
        else dp[i] = 101;
        for(int k=s+1;k<=t;k++){
            if(i-k>=0)
                dp[i] = min(dp[i], dp[i-k]);
        }
        if(a[i]==1) dp[i]++;
        // for(int j=0;j<=l;j++){
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }
    ans = dp[l];
}


int main(){
    cin >> l >> s >> t >> m;
    const int maxlen = ((t/(t-s))+1)*s+5;
    for (int i=0;i<m;i++){
        cin >> ori[i];
    }
    sort();
    for (int i=0;i<m;i++){
        
        if(s2-s1> maxlen){
            s3 += maxlen;
        }
        else{
            s3 += s2-s1;
        }
        a[s3] = 1;
        s1 = s2;
        cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    }
    
    if(l-s1 > maxlen) l=s3+maxlen;
    else l = s3 + l - s1;
    for (int i=0;i<l;i++){
        cout << a[i] << ' ';
    }
    dp_func(maxlen);
    cout << ans;
    return 0;
}