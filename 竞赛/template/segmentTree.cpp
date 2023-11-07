#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

const int N = 1000000;

int a[1000];

struct node {
    int l, r;
    int sum, mmax;
    int add, assign;
    bool is_assigned;

    node() {
        add = 0; assign = 0;
        is_assigned = false;
    }

    void _assign(int value) {
        is_assigned = true;
        assign = value;
        sum = value * (r-l+1);
        mmax = value;
        add = 0;
    }
    void _add(int value) {
        if (is_assigned) assign += value;
        else add += value;
        sum += value * (r - l + 1);
        mmax += value;
    }
}s[N<<2];

void push_up(int i) {
    s[i].sum = s[i*2].sum + s[i*2+1].sum;
    s[i].mmax = max(s[i*2].mmax, s[i*2+1].mmax);
}

void push_down(int i) {
    if (s[i].is_assigned) {
        s[i*2]._assign(s[i].assign);
        s[i*2+1]._assign(s[i].assign);
        s[i].is_assigned = false;
        s[i].assign = 0;
    } else if (s[i].add) {
        s[i*2]._add(s[i].add);
        s[i*2+1]._add(s[i].add);
        s[i].add = 0;
    }
}

void build(int i, int l, int r, int *a){
    s[i].l = l;
    s[i].r = r;
    if (l == r) {
        s[i].sum = s[i].mmax = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(i*2, l, m, a);
    build(i*2+1, m+1, r, a);
    push_up(i);
}

void modify(int i, int l, int r, int value, bool is_assign) {
    if (s[i].l == l && s[i].r == r) {
        if (is_assign) s[i]._assign(value);
        else s[i]._add(value);
        return;
    }
    push_down(i);

    int m = (s[i].l + s[i].r) / 2;
    if (r <= m) modify(i * 2, l, r, value, is_assign);
    else if (l > m) modify(i * 2 + 1, l, r, value, is_assign);
    else {
        modify(i*2, l, m, value, is_assign);
        modify(i*2+1, m+1, r, value, is_assign);
    }

    push_up(i);
}

int query(int i, int l, int r, bool is_max) {
    if (s[i].l == l && s[i].r == r) return is_max ? s[i].mmax : s[i].sum;
    int m = (s[i].l + s[i].r) / 2;
    push_down(i);
    if (r <= m) return query(i*2, l, r, is_max);
    if (l > m) return query(i*2+1, l, r, is_max);
    int ll = query(i*2, l, m, is_max);
    int rr = query(i*2+1, m+1, r, is_max);
    return is_max ? max(ll, rr) : ll + rr;
}

int main(){
    for (int i = 0; i < 1000; i++) {
        a[i] = rand() % 1000;
    }

    build(1, 0, 999, a);

    for (int tt = 0; tt <= 10000; tt++) {
        int op = rand() % 4;
        int l = rand()%1000;
        int r = rand()%1000;
        if (l > r) swap(l, r);

        if (op == 0) {
            int ans = query(1, l, r, true);
            int aans = -1;
            for (int i = l; i <= r; i++) aans = max(aans, a[i]);
            assert(ans == aans);
        }

        if (op == 1) {
            int ans = query(1, l, r, false);
            int aans = 0;
            for (int i = l; i <= r; i++) aans +=  a[i];
            assert(ans == aans);
        }

        if (op == 2) {
            int value = rand()%1000;
            modify(1, l, r, value, true);
            for (int i = l; i<=r; i++) a[i] = value;
        }

        if (op == 3) {
            int value = rand()%100;
            modify(1, l, r, value, false);
            for (int i = l; i <= r; i++) a[i] += value;
        }
    }
    printf("Passed!\n");
    return 0;
}