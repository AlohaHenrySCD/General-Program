#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define _for(i,a,b) for(ll i=(a);i<(b);i++)
#define _rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const ll N = 1e5+5, mod = 1e9+7;
ll n, m, b[N];

struct node {
    ll l, r;
    ll sum, powsum;
    ll assign;
    bool is_assigned;
    node(){
        assign = 0;
        is_assigned = false;
    }
    void _assign(ll v){
        is_assigned = true;
        assign = v;
        sum = v % mod;
        powsum = (v*v) % mod;
    }
}a[N<<2];

inline ll qpow(ll a, ll b){
    ll ans = 1;
    a = (a%mod +mod)%mod;
    for(;b;b>>=1){
        if(b & 1) ans = (a * ans) %mod;
        a = (a*a) %mod;
    }
    return ans;
}

void pup(ll i){
    a[i].sum = (a[i*2].sum + a[i*2+1].sum) % mod;
    a[i].powsum = (a[i*2].powsum + a[i*2+1].powsum) % mod;
}

void pdown(ll i){
    if(!a[i].is_assigned) return;
    a[i*2]._assign(a[i].assign);
    a[i*2+1]._assign(a[i].assign);
    a[i].is_assigned = false;
    a[i].assign = 0;
}

void build(ll i, ll l, ll r){
    a[i].l = l;
    a[i].r = r;
    if (l == r) {
        a[i].sum = b[l];
        a[i].powsum = (ll)b[l] * b[l];
        return;
    }
    ll m = (l + r) / 2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    pup(i);
}

void modify(ll i, ll pos, ll v){
    if(a[i].l==pos && a[i].r==pos){
        a[i]._assign(v);
        return;
    }
    pdown(i);
    ll m = (a[i].l + a[i].r) /2;
    if(m>=pos) modify(i*2, pos, v);
    else if(m<pos) modify(i*2+1, pos, v);
    pup(i);
}

ll query(ll i, ll l, ll r, ll op){
    if(a[i].l==l&&a[i].r==r){
        if(op==1)// sum
            return a[i].sum;
        else// powsum
            return a[i].powsum;
    }
    pdown(i);
    ll m = (a[i].l + a[i].r) /2;
    if(r<=m) return query(i*2, l, r, op);
    if(l>m) return query(i*2+1, l, r, op);
    ll lp = query(i*2, l, m, op);
    ll rp = query(i*2+1, m+1, r, op);
    return lp + rp;
}

int main(){
    cin >> n >> m;
    ll c, x, y;
    _for(i, 1, n+1){
        cin >> b[i];
    }
    build(1, 1, n);
    _for(i, 0, m){
        cin >> c >> x >> y;
        if(c==1){
            modify(1, x, y);
            // cout << query(1, x, x, 1) << ' ';
        } else {
            // _for(j, 1, n*4){
            //     cout << a[j].sum << ' ';
            // }cout << endl;
            ll asum = query(1, x, y, 1)%mod;
            ll len = qpow(y - x + 1, mod-2);
            ll avg = (len * asum) % mod;
            ll ans = ((query(1, x, y, 2)%mod - (avg * asum * 2)%mod + ((avg * avg)%mod*(y -x+1))%mod+mod)%mod * len)%mod;
            // printf("l %d r %d asum %lld len %lld avg %lld ans %lld\n", x, y, asum, len, avg, ans);
            cout << ans << endl;
        }
    }
    return 0;
}