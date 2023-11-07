#include <cstdio>
#include <iostream>
using namespace std;
constexpr int N = 15;
long long f[N + 1][N * N][1<<N];
int n, k;
int popcount(int i) {
    int ret = 0;
    while (i) {
        i -= i & -i;
        ret ++;
    }
    return ret;
}
int main(){
    cin >> n >> k;
    f[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0;j <= k; j++) {
            for (int S0 = 0; S0 < (1 << n); S0++) {
                for (int S = S0;; S = (S - 1) & S0) {
                    int S1 = S0 ^ S;
                    if (!((S1 & (S << 1)) | (S1 & (S >> 1)) | (S1 & (S1 << 1)) | (S1 & (S1 >> 1)))) {
                        f[i + 1][j + popcount(S1)][S1] += f[i][j][S];
                    }
                    if (S == 0) break;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0;i < (1 << n); i++)
        ans += f[n][k][i];
    cout << ans + 1<< endl;
    return 0;
}