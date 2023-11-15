#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10;
int n, a[N][5], t[11][11][11][11][11];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            cin >> a[i][j];
    // if(n==1){
    //     cout << 81; return 0;
    // }
    for(int k=0;k<n;k++){
        for(int i=0;i<=9;i++){
            t[i][a[k][1]][a[k][2]][a[k][3]][a[k][4]]++;
            t[a[k][0]][i][a[k][2]][a[k][3]][a[k][4]]++;
            t[a[k][0]][a[k][1]][i][a[k][3]][a[k][4]]++;
            t[a[k][0]][a[k][1]][a[k][2]][i][a[k][4]]++;
            t[a[k][0]][a[k][1]][a[k][2]][a[k][3]][i]++;
        }
        for(int i=1;i<=9;i++){
            t[(a[k][0]+i)%10][(a[k][1]+i)%10][a[k][2]][a[k][3]][a[k][4]]++;
            t[a[k][0]][(a[k][1]+i)%10][(a[k][2]+i)%10][a[k][3]][a[k][4]]++;
            t[a[k][0]][a[k][1]][(a[k][2]+i)%10][(a[k][3]+i)%10][a[k][4]]++;
            t[a[k][0]][a[k][1]][a[k][2]][(a[k][3]+i)%10][(a[k][4]+i)%10]++;
        }
    }
    int ans=0;
    for(int i1=0;i1<=9;i1++) for(int i2=0;i2<=9;i2++) for(int i3=0;i3<=9;i3++)
    for(int i4=0;i4<=9;i4++) for(int i5=0;i5<=9;i5++){
        if(t[i1][i2][i3][i4][i5]==n) ans++;
    }
    cout << ans;
}