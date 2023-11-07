#include <iostream>
#include <algorithm>

using namespace std;
const int NMAX = 6e5+1;
int n;
struct Lamp{
    int a, b;
}lamp[NMAX];

bool cmp(Lamp a, Lamp b){
    if(a.a < b.a)   return true;
    if(a.a > b.a)   return false;
    return a.b > b.b;
}

int score(){
    sort(lamp, lamp + n, cmp);
    int c=0, d=lamp[0].a;
    long long ret=0;
    for(int i=0;i<n;i++){
        if(c >= lamp[i].a) continue;
        if(d != lamp[i].a){
            d = lamp[i].a;
            c = 0;
        }
        c++;
        ret += lamp[i].b;
    }
    return ret;
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> lamp[j].a >> lamp[j].b;
        }
        cout << score();
    }
    return 0;
}