#include <string>
#include <iostream>
using namespace std;

int main(){
    string a, b, c;
    cin >> a;
    cout << a.length() << std::endl;
    cout << (a.substr(2, 3) == string("abc")) << endl;
    return 0;
}