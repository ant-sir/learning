void h(int);
namespace A {
    class X {
        friend void f(X);       // A::f 是友元
        class Y {
            friend void g();    // A::g 是友元
            friend void h(int); // A::h 是友元，与 ::h 不冲突
        };
    };
    // A::f、A::g 与 A::h 在命名空间作用域不可见
    // 虽然它们是命名空间 A 的成员
 
    X x;
    void g() { // A::g 的定义
        f(x);  // A::X::f 通过实参依赖查找找到
    }
 
    void f(X);       // A::f 的定义
    void h(int) {}     // A::h 的定义
    // A::f、A::g 与 A::h 现在在命名空间作用域可见
    // 而且它们也是 A::X 与 A::X::Y 的友元
}
void A::f(A::X){}

#include <iostream>

int main()
{
    //struct std{}; //隐藏了全局命名空间中的std
    std::cout << "fail\n"; // 错误：对 'std' 的无限定查找找到 struct
    ::std::cout << "ok\n"; // 正确： ::std 找到命名空间 std
    return 0;
}