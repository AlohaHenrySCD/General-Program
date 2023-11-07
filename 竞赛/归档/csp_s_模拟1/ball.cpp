#include <iostream>
#include <set>
using namespace std;

set<int> ans;
const int MOD = 1e9+7;
int n;
struct s
{
    int from = 0; // -1 from l; 1 from r
    bool val;
};
int ori_k;

int compress(s box[]){
    int a=1, ret=0;
    for (int i=0;i<n;i++){
        if(box[i].val == 1) ret += a;
        a *= 2;
    }
    return ret;
}

int dfs(s box[], int k, int i_count){
    for (int i=0;i<n;i++)
        if(k % 2 == 0)
            cout << box[i].val;
    cout << endl;
    if (k%2 == 0) ans.insert(compress(box));
    if (k == 0) return 0;
    int from;
    for (int i=i_count;i<n;i++){
        s v = box[i];
        if(v.val == 1){
            // 修成一个p= i-1, i
            if(i != 0 && (v.from == 0 || v.from == 1) && box[i-1].val == 0){ // r
                cout << k-1 << "r";
                from = v.from;
                v.from = 1;
                s temp = box[i-1];
                box[i-1] = v;
                box[i] = temp;
                dfs(box, k-1, i-1);
                v.from = from;
                box[i] = v;
                box[i-1] = temp;   
            }
            if(i != n - 1 && (v.from == 0 || v.from == -1) && box[i+1].val == 0){ // l
                cout << k-1 << "l";
                from = v.from;
                v.from = -1;
                s temp = box[i+1];
                box[i+1] = v;
                box[i] = temp;
                dfs(box, k-1, 0);
                v.from = from;
                box[i] = v;
                box[i+1] = temp; 
            }
        }
    }
    return 0;
}


int main(){
    int k;
    cin >> n >> k;
    ori_k = k;
    s box[n];
    for(int i=0;i<n;i++)
        cin >> box[i].val;
    // 0 1 反转
    dfs(box, k, 0);
    cout << ans.size() % MOD;
    return 0;
}
