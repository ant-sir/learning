#include<iostream>
using namespace std;

struct A {
    int a;
    char* p;
//private:
    struct AA {
        int b;
    };
//public:
    AA aa;
    void f(int b){cout << a << ' ' << b << endl;}
};


int main()
{
    int A::*pa = &A::a;
    A obj_a;
    obj_a.*pa = 100;
    cout << obj_a.*pa << endl;

    A::AA A::*paa = &A::aa;

    void (A::*pf)(int) = &A::f;
    (obj_a.*pf)(10);

    return 0;
}