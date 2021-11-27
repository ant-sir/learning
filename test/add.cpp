#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class Adder {
public:
    Adder (T a, T b) : m_a (a), m_b (b) {}
    /* T Cal (void) {
        return m_a + m_b;
    } */
    
    T Cal (void);
   
    /* template<class V> void foo (V v) {
        cout << v << endl;
    } */
    
    template<class V>
    void foo (V v);
   
private:
    T m_a;
    T m_b;
};

// template<>
// class Adder<char*> {
// public:
//     Adder (char* a, char* b) : m_a (a), m_b (b) {}
//     /* char* Cal (void) {
//         return strcat (m_a, m_b);
//     } */
//     char* Cal (void);
//     /* template<class V>
//     void foo (V v) {
//         cout << v << endl;
//     } */
//     template<class V>
//     void foo (V v);
// private:
//     char* m_a;
//     char* m_b;
// };

// char* Adder<char*>::Cal (void) {
//     return strcat (m_a, m_b);
// }
// template<class V>
// void Adder<char*>::foo(V v) {
//     cout << v << endl;
// }

template<>
char* Adder<char*>::Cal (void) {
    return strcat (m_a, m_b);
}

template<>
template<>
char* Adder<char*>::foo (char* v) {
    cout << v << endl;
}

template<class T>
T Adder<T>::Cal (void) {
    return m_a + m_b;
}
template<class T>
template<class V>
void Adder<T>::foo (V v) {
    cout << v << endl;
}

int main (void) {
    Adder<int> a1 (100, 200);
    cout << a1.Cal () << endl;
    Adder<double> a2 (1.23, 9.33);
    cout << a2.Cal () << endl;
    Adder<string> a3 ("hello", " world !");
    cout << a3.Cal () << endl;
    a3.foo<int> (120);
    a3.foo<string> ("你好！");
    char s1[128] = "hello";
    char s2[] = " world !";
    Adder<char*> a4 (s1, s2);
    cout << a4.Cal () << endl;
    return 0;
}