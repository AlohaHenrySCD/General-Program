#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int L = 105;
map<char, int> ext;
string tar;
char op, c;
string s, e;
bool errflag, nflag;
int t, n, tn, maxn, l;

struct thr{
    char c; int n; int f;
};
vector<thr> nn;


int stoint(string a){
    int siz = a.size();
    int b= 1, ret = 0;
    for(int i=0;i<siz;i++){
        ret += b* (a[siz-i-1] - '0');
        // printf("a[siz-i]%d, siz-i %d\n", a[siz-i], siz-i);
        b*= 10;
    }
    return ret;
}

int main(){
    cin >> t;
    for(int iter=0;iter<t;iter++){
        cin >> l >> tar;
        errflag = 0, n = 0, maxn = 0, nflag = 0;
        ext.clear();
        while(!nn.empty()) nn.pop_back();
        tn = 0;
        if(tar[2]!='1'){
            int siz = tar.size() - 5;
            int cnt = 1;
            for(int i=0;i<siz;i++){
                tn += cnt* (tar[3+siz-i] - '0');
                cnt*= 10;
            }
        }
        for(int i=0;i<l;i++){
            cin >> op;
            if(op=='F'){
                cin >> c >> s >> e;
                if(s=="n") s = "102"; if(e=="n") e = "102";
                int st = stoint(s), ed = stoint(e);
                if(ext[c]>=1) errflag = true;
                ext[c]++;
                if(st==ed) {
                    nn.push_back({c, 0, 0});
                }
                else if(st > ed){
                    nn.push_back({c, 0, 1});
                    nflag = true;
                }
                else if(ed==102) n++, nn.push_back({c, 1, 0});
                else nn.push_back({c, 0, 0});
            } else {
                if(nn.empty()) {errflag = true; continue;}
                if(nn.back().f) nflag = false;
                ext[nn.back().c]--; 
                n -= nn.back().n;
                nn.pop_back();
            }
            if(!nflag) maxn = max(maxn, n);
        }
        if(!nn.empty()||errflag)
            cout << "ERR\n";
        else if(tn==maxn)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}