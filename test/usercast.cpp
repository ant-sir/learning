#include <iostream>
using namespace std;

struct To {
    To() = default;
    To(const struct From&) {
        cout << "To::To(const struct From &)" << endl;
    }  // 转换构造函数
    To(const To &) {
        cout << "To::To(const To &)" << endl;
    }
};
 
struct From {
    operator To() {
        cout << "From::operator To() const" << endl;
        return To();
    } // 转换函数
    From() = default;
    From(const From &) {
        cout << "From::From(const From &)" << endl;
    }
};
 
int main()
{
    From f;
    To t1(f); // 直接初始化：调用构造函数
    cout << "================1=================" << endl;
// （注意，如果转换构造函数不可用，那么会选择隐式的复制构造函数，且调用转换函数以准备其参数）
    To t2 = f; // 复制初始化：有歧义
    cout << "================2=================" << endl;
// （注意，如果转换函数来自非 const 类型，例如 From::operator To(); 
//  那么它在这种情况下会替代构造函数被选中）
    To t3 = static_cast<To>(f); // 直接初始化：调用构造函数
    cout << "================3=================" << endl;
    const To& r = f; // 引用初始化：有歧义
}