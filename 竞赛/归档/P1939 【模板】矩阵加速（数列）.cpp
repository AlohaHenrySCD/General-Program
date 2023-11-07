#include <iostream>
using namespace std;
const long MOD = 1e9+7;
long n, T;
struct matrix{
    long a[4][4];
} matr;

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1;i <= 3; i++) {
        for (int j = 1;j <= 3; j++) {
            c.a[i][j] = 0;
            for (int k = 1; k <= 3; k++)
                c.a[i][j] += a.a[i][k] * b.a[k][j];
                c.a[i][j] = c.a[i][j] % MOD;
        }
    }
    return c;
}

matrix power(matrix matr, long n) {
    if(n<=1)return matr;
    matrix ret=matr;
    while(n>0) {
        if(n%2==1) ret = mul(matr,ret);
        n/=2;
        matr = mul(matr,matr);
    }
    return ret;
}

int main(){
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) matr.a[i][j] = 0;
    matr.a[1][1] = 1; matr.a[3][1] = 1; matr.a[1][2] = 1; matr.a[2][3] = 1;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        matrix ans = power(matr, n-2);
        cout << ans.a[1][1] << endl;
    }
    return 0;
}