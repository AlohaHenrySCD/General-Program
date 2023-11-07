#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;
const int mod = (int)1e9 + 7;
struct MyHash {
    int operator()(const string &s) const {
        int ret = 0;
        for (int i = 0;i < s.length(); i++) {
            ret = (ret * 131 + (s[i] - 'a')) % mod;
        }
        return ret;
    }
};

std::unordered_map<string, int, MyHash> m;
int main(){
    int cur = 0;
    string st;
    while (true) {
        cin >> st;
        auto it = m.find(st);
        if (it == m.end()) {
            cout << "No" << endl;
            m[st] = ++cur;
        } else {
            cout << it->second << endl;
        }
    }
}