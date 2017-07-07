#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int a = 69;
    int* p = &a;
    int* pp = &p;
    cout << a << endl;
    cout << p << endl;
    cout << &a << endl;
    cout << *p << endl;
    cout << &p << endl;
    cout << pp << endl;
    return 0;
}