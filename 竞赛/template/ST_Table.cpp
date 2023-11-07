
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
template <int N, typename T, typename FT>
class ST_Table {
    constexpr static int L = (int)ceil(log(N));
    T f[N][L];
    FT& ft;
public:
    ST_Table(T *a, FT&& ft) : ft(ft) {
        for (int i = 0;i < N; i++) 
            f[i][0] = a[i];
        for (int j = 1; j < L; j++) {
            int l = 1 << j;
            for (int i = 0;i < N - l + 1; i++)
                f[i][j] = ft(f[i][j - 1], f[i + l / 2][j - 1]);
        }
    }
    T query(int l, int r) {
        int k = floor(log(r - l + 1));
        //printf("ft[%d][%d] = %d, ft[%d][%d] = %d\n", l, k, f[l][k], r - (1<<k) + 1, k , f[r - (1<<k)+1][k]);
        return ft(f[l][k], f[r - (1<<k) + 1][k]);
    }
};

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    auto mymax = [](int a, int b){ return max(a, b); };

    ST_Table<10, int, decltype(gcd)> st(a, gcd);

    while (true) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l,r) << endl;
    }
}