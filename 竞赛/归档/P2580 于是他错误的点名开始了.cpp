#include <map>
#include <iostream>
#include <cstdio>
#include <string>
#define _for(i, s, e) for(int i=(s);i<e;i++)
#define _rep(i, s, e) for(int i=(s);i<=e;i++)
using namespace std;
const int Nmax = 1e4+5, Mmax = 1e5+5;
int n, m;
string s;
map<string, int> a;

int main(){
    cin >> n;
    _for(i, 0, n){
        cin >> s;
        a[s] = 1;
    }
    cin >> m;
    _for(i, 0, m){
        cin >> s;
        if(a[s]==1){
            a[s]++; cout << "OK\n";
        } else if(a[s]==2){
            cout << "REPEAT\n";
        } else {
            cout << "WRONG\n";
        }
    }
    return 0;
}