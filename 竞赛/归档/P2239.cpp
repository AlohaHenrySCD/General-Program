#include <iostream>
#include <cstdio>
using namespace std;
int n, m, i, j, q;

int main(){
    cin >> n >> i >> j;
    int ori_i = i, ori_j = j;
    i = i > n/2? n - i + 1 : i;
    j = j > n/2? n - j + 1 : j;
    m = min(i, j) - 1;
    for(int k=0;k<m;k++, n-=2)
        q += 4*n - 4;
    ori_i -= m; ori_j -= m;
    int cnt = 1;
    for(int i=1, j=1;!(i==ori_i&&j==ori_j);){
        // printf("ori_i %d i %d  ori_j %d j %d n %d\n", ori_i, i, ori_j, j, n);
        if(i==1&&j<n) j++;
        else if(j==n&&i<n) i++;
        else if(j>1&&i==n) j--;
        else if(j==1&&i>1) i--;
        cnt++;
    }
    int ans = q + cnt;
    cout << ans;
}