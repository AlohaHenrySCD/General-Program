#include <iostream>
#include <vector>
using namespace std;
const int MAXS = 2e5+1;
int s, vis[MAXS], dp[MAXS], p[MAXS];
// vector<int> p;

void func(int s){
    vis[1] = 0; vis[2] = 1; // 0->lose 1->win

}


int main(){
    for(int i=1;i*i<MAXS;i++){
        if(!p[i])
            for(int j=2;j<=i;j++){
                p[i*j] = 1;
            }
    }
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s;
        func(s);
    }
    return 0;
}