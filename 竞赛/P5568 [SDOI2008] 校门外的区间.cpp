#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int N = 12;
int n, m, a[N];

struct node{
    int l, r;
    int rev, assign;
    node(){
        assign = -1;
        rev = 0;
    }
}s[N<<3];

void pd(int i){
    // 先赋值
    if(s[i].assign!= -1){
        s[i<<1].assign = s[i<<1|1].assign = s[i].assign;
        s[i<<1].rev = s[i<<1|1].rev = 0;
        s[i].assign = -1;
    }
    // rev
    if(s[i].rev==1){
        (s[i<<1].assign != -1 ? s[i<<1].assign : s[i<<1].rev) ^= 1;
        (s[i<<1|1].assign != -1 ? s[i<<1|1].assign : s[i<<1|1].rev) ^= 1;
        s[i].rev = 0;
    }
}

void build(int i, int l, int r){
    //printf("build(%d,%d,%d)\n", i, l, r);
    s[i].l = l;
    s[i].r = r;
    if(l==r){
        s[i].assign = 0; s[i].rev = 0;
        return;
    } 
    s[i].assign = -1;
    s[i].rev = 0;
    m = (l + r)>>1;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
}

void modify(int i, int l, int r, int op, int v){
    //printf("modify(%d,%d,%d,%d,%d)\n", i, s[i].l, s[i].r, l, r);
    if(s[i].l==l&& s[i].r==r){
        if(op==1){// rev
            (s[i].assign != -1 ? s[i].assign : s[i].rev) = 1;
        } else {
            s[i].rev = 0;
            s[i].assign = v;
        }
        return;
    }
    pd(i);
    int m = (s[i].l + s[i].r)>>1;
    if(r<=m) modify(i*2, l, r, op, v);
    else if(l>m) modify(i*2+1, l, r, op, v);
    else
        modify(i*2, l, m, op, v), modify(i*2+1, m+1, r, op, v);
}

void query(int i, int l, int r){
    if(l==r){
        int sign = s[i].assign;
        a[l] = s[i].rev==0 ? sign : !sign;
        return;
    }
    pd(i);
    int m = (l+r)>>1;
    query(i*2, l, m);
    query(i*2+1, m+1, r);
}

void read(int& l, int& r, string set){
    stringstream sin(set);
    char lc, rc, mc;
    int lv, rv;
    sin >> lc >> lv >> mc >> rv >> rc;
    //cout << lc << lv << " " << rv << rc << endl;
    l = lv * 2 + (lc == '(') + 1;
    r = rv * 2 + (rc == ']');
}

int main(){
    char op;
    string set;
    build(1, 1, N);
    auto show = [&](){
        query(1,1,N);
        _rep(i, 1, N-1){
            if (a[i]) cout << i << endl;
        }
        printf("show finished\n");
    };
    show();
    while(cin >> op){
        cin >> set;
        int l=0, r=0;
        read(l, r, set);
        //cout << set << endl;
        cout << l << " " << r << endl;
        if(op=='U') modify(1, l, r, 2, 1);
        else if(op=='I') modify(1, 1, l-1, 2, 0), modify(1, r+1, N, 2, 0);
        else if(op=='D') modify(1, l, r, 2, 0);
        else if(op=='C') modify(1, 1, N, 1, 0), modify(1, 1, l-1, 2, 0), modify(1, r+1, N, 2, 0);
        else if(op=='S') modify(1, l, r, 1, 0);
        cout << op << " " << set << endl;
        show();
    }
    
    return 0;
}