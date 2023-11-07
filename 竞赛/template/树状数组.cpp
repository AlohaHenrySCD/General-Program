
constexpr int N = 1000010;

inline int lowbit(int k) {
    return k & -k;
}

int s[N];

void add(int x, int p) {
    // a[x] += p;
    for (int i = x; i <= N; i += lowbit(i))
        s[i] += p;
}

int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i))
        ret += s[i];
    return ret;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

