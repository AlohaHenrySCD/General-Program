const int N = 500;
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

double a[N][N+1];

const double eps = 1e-10;

void show(int n){
    for (int i = 0;i < n;i++)
        for (int j = 0;j <= n;j++)
            printf("%10.3lf%c", a[i][j], j == n ? '\n' : ' ');
}

void guass(int n) {
    bool flag = false;
    for (int i = 0;i < n;i ++) {
        int r = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
        if (r != i)
            for (int j = 0; j <= n; j++)
                swap(a[r][j], a[i][j]);

        if (fabs(a[i][i]) < eps) {
            // 无解
            flag = true;
            if (a[i][n] != 0) cout << "无解" << endl;
            cout << "无解或者无穷多解" << endl; 
        } else {
        //show(n);
            for (int j = i+1; j < n;j++) {
                double f = a[j][i] / a[i][i];
                for (int k = i; k <= n; k++)
                    a[j][k] -= f * a[i][k];
            }
        }
    }
    //上三角矩阵。

    if (flag) {
        // 无穷多解
    } else {
        for (int i = n - 1; i >= 0; i--) {
            a[i][n] /= a[i][i];
            for (int j = i - 1; j >= 0; j--) {
                a[j][n] -= a[j][i] * a[i][n];
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j <= n;j++)
            cin >> a[i][j];

    guass(n);
    for (int i = 0;i < n;i++)
        cout << a[i][n] << endl;

    return 0;
}