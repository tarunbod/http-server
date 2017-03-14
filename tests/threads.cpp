#include <iostream>
#include <thread>

using namespace std;

void foo();
void bar();

int main() {
    std::thread t1 (foo);
    std::thread t2 (bar);

    cout << "foo/bar are concurrent..." << endl;

    t1.join();
    t2.join();

    cout << "foo bar done" << endl;

    return 0;
}

void foo() {
    int c = 1;
    while (c <= 100) {
        cout << "lmao " << c << ";" << endl;
        c++; // lol
    }
}

void bar() {
    int c = 100;
    while (c >= 1) {
        cout << "ayy lmao " << c << ";" << endl;
        c--;
    }
}

