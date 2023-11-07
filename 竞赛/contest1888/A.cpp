#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define pii pair<int, int>
using namespace std;
int t, n, k;
string s;
int cnt[30], ans;

int main(){
    cin >> t;
    _for(i, 0, t){
        cin >> n >> k >> s;
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        for(auto let : s){
            if(cnt[let - 'a']==1){
                cnt[let - 'a'] = 0;
                ans--;
            } else {
                cnt[let - 'a']++;
                ans++;
            }
        }
        if((ans-k)<=1){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}