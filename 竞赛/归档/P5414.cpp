#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int t, n, k[N], f[N], maxc, sum;

int main(){
    cin >> t;
    for(int iter=0;iter<t;iter++){
        cin >> n;
        sum = 0, maxc = -1e9;
        memset(f, 0, sizeof(f));
        for(int i=0;i<n;i++)
            cin >> k[i], sum += k[i];
        for(int i=0;i<n;i++){
            f[i] = k[i];
            for(int j=0;j<i;j++)
                if(k[j]<=k[i])
                    f[i] = max(f[i], f[j]+k[i]);
                    // printf("f[i] %d i %d j %d \n", f[i], i, j),
            maxc = max(maxc, f[i]);
        }
        cout << sum - maxc << endl;
    }
}