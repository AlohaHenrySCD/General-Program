#include <cstdio>

union {
    float a;
    int b;
}a;

int main(){
    int a = 123456789;
    float b = (float)a;
    int c = b;
    printf("%d\n",c);
}