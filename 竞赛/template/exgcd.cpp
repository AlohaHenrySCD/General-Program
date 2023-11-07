#include <cstdio>
int exgcd(int a, int b, int &x, int &y) {
    int ret = 0;
    if (b == 0) {
        x = 1; y = 0;
        ret = a;
    } else {
        ret = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, ret);
    return ret;
}

int main() {
    while (true) {
        int a, b;
        int x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
    }
}