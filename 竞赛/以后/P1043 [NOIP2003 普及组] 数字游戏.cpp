#include <iostream>
#include <cstring>
using namespace std;
const int NMAX = 52, MMAX = 11;
int n, m, a[NMAX], dpmin[NMAX][MMAX], dpmax[NMAX][MMAX];

void prt(int i, int j){
    cout << i << ' ' << j << ' ' << endl;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << dpmax[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    memset(dpmin, 0x3f, sizeof(dpmin));
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i=1;i<=n;i++){
        cnt += a[i];
        cnt = ((cnt % 10) + 10) % 10;
        dpmax[i][1] = cnt;
        dpmin[i][1] = cnt;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m&&j<=i;j++){
            cnt = 0;
            for(int k=1;k<=i-j+1;k++){
                cnt += a[i-k+1];
                cnt = ((cnt % 10) + 10) % 10;
                cout << i-k << ' ' << j-1 << ' ';
                cout << "dp " << dpmax[i-k][j-1] << " cnt " << a[i-k+1] << ' ';
                dpmax[i][j] = max(dpmax[i][j], dpmax[i-k][j-1]*cnt);
                dpmin[i][j] = min(dpmin[i][j], dpmin[i-k][j-1]*cnt);
            }
            prt(i, j);
        }
    }
    cout << dpmin[n][m] << endl << dpmax[n][m];
}