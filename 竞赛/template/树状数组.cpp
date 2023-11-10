
constexpr int N = 1000010;

int n, c[N], a[N];
int query(int x, int sum = 0){
    for(;x;x-=(x&(-x))) sum += c[x];
    return sum;
}
int add(int x, int v){
    for(;x<=n;x+=(x&(-x))) c[x] += v;
}

// for(int i=0;i<n;i++) add(i, a[i]);

// inline int lowbit(int k) {
//     return k & -k;
// }
// int s[N];
// void add(int x, int p) {
//     // a[x] += p;
//     for (int i = x; i <= N; i += lowbit(i))
//         s[i] += p;
// }
// int query(int x) {
//     int ret = 0;
//     for (int i = x; i; i -= lowbit(i))
//         ret += s[i];
//     return ret;
// }
// // int query(int l, int r) {
// //     return query(r) - query(l - 1);
// // }
