#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long 
using namespace std;
const int MAXN = 105;
int n, d[MAXN][MAXN], lim[MAXN][MAXN];
ll q;


ll cal_p(int day){
    int t[MAXN][MAXN];
    for (int i =0; i<n; i++)
		for (int j =0; j<n; j++)
			t[i][j]=d[i][j];
    // cout << "new\n";
    for(int i=0;i<n;i++){
        int val = day/n + (day%n>=i+1?1:0);
        for(int j=0;j<n;j++){
            // t[i][j] = max(d[i][j]-val-val, lim[i][j]);
            // t[j][i] = max(d[j][i]-val-val, lim[j][i]);
            t[i][j] = max(lim[i][j], t[i][j]-val);
		    t[j][i] = max(lim[j][i], t[j][i]-val);
        }
    }
    for(int i=0;i<n;i++){
        int val = day/n + (day%n>=i+1?1:0);
        for(int j=0;j<n;j++){
            bool a = (d[i][j]-val-val == t[i][j]);
            cout << (d[i][j]-val == t[i][j]) || a;
        }
        cout << endl;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
            }
    ll sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            sum += t[i][j];
        }
    return sum;
}


int main(){
    cin >> n >> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> lim[i][j];
        }
    int l=0, r=int(1e7), mid;
    int ans = 1e9;
    while(l<=r){
        mid = (l+r)/2;
        if(cal_p(mid)<=q){
            r = mid-1;
            ans = min(mid, ans);
        } else 
            l = mid+1;
    }
    cout << (ans == int(1e9) ? -1 : ans);
    return 0;
}