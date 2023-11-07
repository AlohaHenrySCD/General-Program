#include <iostream>
using namespace std;
int n, a[102], ldp[102], rdp[102], kmax=0;

void dpfunc(){
    for(int i=1;i<=n;i++)
        for(int k=1;k<i;k++)
            if(a[k]<a[i])
                ldp[i] = max(ldp[i], ldp[k]+1);
    for(int i=n;i>0;i--)
        for(int k=n;k>i;k--)
            if(a[k]<a[i])
                rdp[i] = max(rdp[i], rdp[k]+1);
    for(int i=1;i<=n;i++){ // 都取了i？不可能
        // cout << ldp[i] << " " << rdp[i] << endl;
        kmax = max(kmax, ldp[i]+rdp[i]);
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dpfunc();
    cout << n - kmax - 1;
    return 0;
}