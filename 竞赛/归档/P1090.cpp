#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e4+5;
int n, a[N], ans;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], q.push(a[i]);
    for(int i=0;i<n-1;i++){
        int tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        ans += tmp;
        q.push(tmp);
    }
    cout << ans;
}