#include <iostream>
using namespace std;
const int MAXN = 1e5+50;
int n, a[MAXN];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int s = 0;
    int ans = 0;
    for(int i=1;i<n-1;i++){
        if(a[i]<a[i-1]){
            ans += a[i-1] - s;
            s = a[i];
        }
    }
    int i = n-1;
    if(a[i]<a[i-1]){
        ans += a[i-1] - s;
        cout << ans;
    } else {
        ans += a[i] - s;
        cout << ans;
    }
}