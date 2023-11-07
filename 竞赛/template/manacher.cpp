#include <string>

using namespace std;

const int N = 10000100;
int L[N];

int manacher(string s) {
    
    string cur(s.length() * 2 + 1, '*');
    for (int i = 0;i < s.length(); i++)
        cur[i * 2 + 1] = s[i];
    int ans = 0;
    int p = 0; L[0] = 0;
    for (int i = 1;i < cur.length(); i++) {
        if (p + L[p] > i)
            L[i] = min(L[2 * p - i], L[p] + p - i);
        while (L[i] < i && i + L[i] < cur.length() - 1 && cur[i - L[i] - 1] == cur[i + L[i] + 1])
            L[i]++;
        if (i + L[i] > p + L[p]) p = i;
        ans = max(ans, L[i]);        
    }
    return ans / 2;
}

