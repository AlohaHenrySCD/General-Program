#include <string>
#include <iostream>
using namespace std;

int fail[1000000];
int main(){
    string a, b;
    cin >> a >> b;
    fail[0] = -1;

    for (int i = 1; i < a.length(); i++) {
        int x = fail[i - 1];
        while (x != -1 && a[x + 1] != a[i]) x = fail[x];
        fail[i] = a[x+1] == a[i] ? x + 1 : -1;
    }

    int x = -1; // 均摊复杂度O(n+m)
    for (int i = 0; i < b.length(); i++) {
        while (x != -1 && a[x+1] != b[i]) x = fail[x];
        x = a[x+1] == b[i] ? x+1 : -1;
        if (x == a.length() - 1){
            cout << "Matched at " << i - a.length() + 1 << std::endl;
            x = fail[x];
        }
    }

    return 0;
}
