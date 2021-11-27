#include <iostream>

using namespace std;

class B {
public:
    virtual void f(int a = 10) {}
};

class C : public B {
public:
    void f(int a = 20) {
        cout << "a = " << a << endl;
    }
};



int main()
{
    C c;
    B &r = c;
    r.f();
    c.f();
    return 0;
}